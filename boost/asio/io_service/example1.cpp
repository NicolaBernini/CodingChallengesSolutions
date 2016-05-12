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

int main(void)
{
    run(3); 
}


