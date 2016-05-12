/**
  * @file example1.cpp 
  * @brief Tests the Boost Asio IO_Service creating a Thread Pool and Pushing Jobs to be performed 
  * @note Compile with -pthread -lboost_system -lboost_thread 
  */

#include <iostream>
#include <boost/system/error_code.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>

// Minor fixes applied to http://thisthread.blogspot.com/2011/04/multithreading-with-asio.html

boost::mutex mio; // 1
 
void logMsg(char* reason, int i)
{
    boost::lock_guard<boost::mutex> lock(mio); // 2.
    std::cout << reason << " for " << i << " at " << std::time(0) << std::endl;
}

void jobOne(int secs) // 3.
  {
    logMsg("Start jobOne", secs);
    boost::this_thread::sleep(boost::posix_time::millisec(1000 * secs));
    logMsg("End jobOne", secs);
  }
 
  void jobTwo(int millisecs)
  {
    logMsg("Start jobTwo", millisecs);
    boost::this_thread::sleep(boost::posix_time::millisec(millisecs));
    logMsg("End jobTwo", millisecs);
  }

void run (int tNumber)		// 1.
{
  boost::asio::io_service svc;	// 2.
  boost::thread_group threads;

  {
    std::auto_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(svc)); //3.
    for (int i = 0; i < tNumber; ++i)	// 4.
      threads.create_thread (boost::bind (&boost::asio::io_service::run, &svc));

    svc.post(std::bind(jobOne, 2)); // 5.
    svc.post(std::bind(jobOne, 1));
    svc.post(std::bind(jobTwo, 500));

    //svc.stop ();			// 6.
  }
  threads.join_all ();		// 7.
}

int main(int argc, char** argv)
{
 // Default Value
 int t_num = 3;
 int t_val = 0; 
 std::cout << "Boost Asio IO_Service Test1" << std::endl; 
 if(argc > 1)
 {
  if(t_val = atoi(argv[1]) > 0)
  {
   std::cout << "Setting the Number of Jobs to " << t_val << std::endl; 
   t_num = t_val; 
  }
  else 
  {
   std::cout << "Invalid Input Argument, using default value" << std::endl; 
  }
 }
 std::cout << "Running " << t_num << " jobs " << std::endl; 
 run(t_val); 
}


