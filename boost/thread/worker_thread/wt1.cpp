#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <queue>
#include <boost/date_time/posix_time/posix_time.hpp>

/**
  * @brief The Class that contains the Producer Consumer double thread solution 
  */
class Test
{
public:
    /**
      * @brief The Default Constructor creates the Worker or Consumer Thread which waits for Data to be processed 
      */
    Test()
    {
        // Worker Thread containing the Blocking Function 
        thread = boost::thread(boost::bind(&Test::thread_func, this));
    }
    
    /**
      * @brief The Destructor is triggered by the object destroying event and it manages the Worker Thread closing 
      * @note The Worker Thread is interrupted and a sync join is performed 
      */
    ~Test()
    {
        thread.interrupt();
        thread.join();
    }
    
    /**
      * @brief The Producer Thread (main thread) gets the mutex when pushing data into the shared queue appunto 
      */
    void run()
    {
        for (size_t i = 0; i < 10; ++i) {
            boost::lock_guard<boost::mutex> lock(mutex);
            queue.push(i);
            condition_var.notify_one();
        }
    }

private:
    /**
      * @brief The Worker Thread Function which processes just the last element 
      * @note The choice to process just the last element is by design and can be easily changed 
      */
    void thread_func()
    {
        //** Gets out of the while when interruption is requested 
        while (!boost::this_thread::interruption_requested())
        {
            //** Internal scope to perform scoped lock 
            {
                boost::unique_lock<boost::mutex> lock(mutex);
                std::cout << "Processing Element" << std::endl; 
                //** Waiting for an element 
                while (queue.empty())
                    //** Mutex release while sleeping and mutex take when awake exploiting the condition variable facility 
                    condition_var.wait(lock);
                std::cout << "Got element " << queue.front() << std::endl; 
                //** Dropping the other commands 
                while(!queue.empty())
                    queue.pop();
            }
        }
    }

private:
    /**
      * @brief The Worker Thread 
      */
    boost::thread thread;
    
    /**
      * @brief The Sync Mutex to Access the Shared Queue 
      */
    boost::mutex mutex;
    
    /**
      * @brief The Condition Variable to access the Data efficiently 
      */
    boost::condition_variable condition_var;
    
    /**
      * @brief The Shared Data Queue appunto 
      */
    std::queue<int> queue;
};

int main()
{
    //** Creates the object and Worker thread is ready 
    Test test;
    //** Runs the Producer which after pushing data awakes the worker to perform processing 
    test.run();
    
    //boost::this_thread::sleep(boost::posix_time::milliseconds(100));

    return 0;
}
