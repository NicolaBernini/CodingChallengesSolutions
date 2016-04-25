/**
  * @file wt3.cpp 
  * @brief The main thread creates up to N = 1 parallel threads and detaches them (so noi sync join is involved) 
  * @note To see it running check at http://coliru.stacked-crooked.com/a/ee517476a341ed4e 
  */

#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

/**
  * @brief The Mutex to perform Sync Write Access to the Global Shared Counter 
  */
boost::mutex m; 

/**
  * @brief The Global Shared Counter which defines how many Worker Threads are currently running 
  */
int cont=0; 

/**
  * @brief The Worker Thread Function 
  */
void f_thread1(int i)
{
    std::cout << "[Thread " << i << "] Started cont = " << cont << std::endl; 
    std::cout << "[Thread " << i << "] Finished" << std::endl; 
    boost::this_thread::sleep(boost::posix_time::milliseconds(3));
    //** The Global Shared Counter Decrement in the Scoped Lock 
    {
        boost::unique_lock<boost::mutex> lock(m); 
        cont--; 
    }
}

int main()
{   
    for(int i=0; i<32; ++i)
    {
        //** Runs a new Worker Thread only if the number of currently running Worker Threads is zero 
        if(cont==0)
        {
            //** The Global Shared Counter Increment in the Scoped Lock 
            {
                boost::unique_lock<boost::mutex> lock(m); 
                cont++; 
            }
            //** Thread is created and detached as there is no need to join it 
            auto t = new boost::thread(boost::bind(f_thread1, i)); 
            t->detach();
        }
        boost::this_thread::sleep(boost::posix_time::milliseconds(3));
    }
    
}

