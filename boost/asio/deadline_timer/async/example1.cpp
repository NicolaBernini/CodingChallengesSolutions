#include <iostream>
#include <boost/system/error_code.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

/**
  * @brief The Timer Callback Function which reschedule the timer after 1 sec for 5 times 
  */
void callback_func(const boost::system::error_code& e, boost::asio::deadline_timer* pt, int* pcont)
{
    std::cout << "[Timer Callback Func] Iteration = " << *(pcont) << std::endl; 
    //** Checks if a new timer needs to be rescheduled 
    if(*(pcont) < 5)
    {
       //** Increments the counter 
        ++(*pcont); 
        //** Updates the absolute timer target time (when the callback function will be called again)
        pt->expires_at(pt->expires_at() + boost::posix_time::seconds(1)); 
        //** Reschedule a new job for the timer 
        pt->async_wait(boost::bind(callback_func, boost::asio::placeholders::error, pt, pcont)); 
    }
}


int main()
{
    /**
      * @brief The Counter 
      * @note It lives in the main() scope and its pointer is passed to the callback function (different thread) for adding up, however it is safe as the main thread (i.e. the scope of this variable) will not terminate until there is no more job for the timer
      */
    int cont=0; 
    /**
      * @brief The Boost Asio IO_Service Engine used for Async Communications 
      */
    boost::asio::io_service ios; 
    
    //** Define a timer specifying the IO_Service Engine and the Target Time 
    boost::asio::deadline_timer t(ios, boost::posix_time::seconds(1)); 
    //** Schedule the job 
    t.async_wait(boost::bind(callback_func, boost::asio::placeholders::error, &t, &cont)); 
    
    //** It blocks the Main Thread Execution until there is no more job for the timer 
    ios.run(); 
}
