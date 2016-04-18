#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <queue>
#include <boost/date_time/posix_time/posix_time.hpp>

class Test
{
public:
    Test()
    {
        // Worker Thread containing the Blocking Function 
        thread = boost::thread(boost::bind(&Test::thread_func, this));
    }

    ~Test()
    {
        //thread.interrupt();
        thread.join();
    }

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
      * @brief The Worker Thread which processes just the last element 
      */
    void thread_func()
    {
        while (!boost::this_thread::interruption_requested())
        {
            {
                boost::unique_lock<boost::mutex> lock(mutex);
                std::cout << "Processing Element" << std::endl; 
                //** Waiting for an element 
                while (queue.empty())
                    condition_var.wait(lock);
                std::cout << "Got element " << queue.front() << std::endl; 
                //** Dropping the othe commands 
                while(!queue.empty())
                    queue.pop();
            }
        }
    }

private:
    boost::thread thread;
    boost::mutex mutex;
    boost::condition_variable condition_var;
    std::queue<int> queue;
};

int main()
{
    Test test;
    test.run();
    
    //boost::this_thread::sleep(boost::posix_time::milliseconds(100));

    return 0;
}
