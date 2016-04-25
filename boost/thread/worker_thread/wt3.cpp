#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

int cont=0; 

void f_thread1(int i)
{
    std::cout << "[Thread " << i << "] Started cont = " << cont << std::endl; 
    std::cout << "[Thread " << i << "] Finished" << std::endl; 
    boost::this_thread::sleep(boost::posix_time::milliseconds(3));
    cont--; 
}

int main()
{   
    for(int i=0; i<32; ++i)
    {
        if(cont==0)
        {
            cont++; 
            auto t = new boost::thread(boost::bind(f_thread1, i)); 
            t->detach();
        }
        boost::this_thread::sleep(boost::posix_time::milliseconds(3));
    }
    //std::cout << "Out of the for " << std::endl; 
    
}

