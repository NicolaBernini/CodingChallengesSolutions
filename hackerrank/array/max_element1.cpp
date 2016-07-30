/**
  * @brief The Solution at the Push, Pop and Get Max Element Challenge 
  * @note Link at https://www.hackerrank.com/challenges/maximum-element
  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
inline void f_PushElement(vector<T>& in_vec, const T in_elem, T& in_lastmax){
    in_vec.push_back(in_elem); 
    if(in_elem>in_lastmax)
        in_lastmax=in_elem; 
};


template <typename T>
inline void f_DeleteTopElem(const vector<T>& in_vec){
    in_vec.pop_back(); 
};


template <typename T>
inline T f_GetMax(const vector<T>& in_vec){
       return *(std::max_element(in_vec.begin(), in_vec.end())); 
};


typedef uint64_t int_t; 
std::vector<int_t> vec; 


int_t m_last_max=0; 
bool t_flag=false; 

int main() {
    //** Number of Queries 
    int_t N; 
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin >> N; 
    
    int t_cmd=0; 
    int_t t_param=0; 
    
    for(int_t i=0; i<N; ++i)
    {
        cin >> t_cmd; 
        switch(t_cmd)
        {
            case 1: 
                cin >> t_param;
                f_PushElement(vec, t_param, m_last_max); 
                //vec.push_back(t_param); 
                //cout << "Added " << t_param << endl; 
            break; 
            
            case 2: 
                vec.pop_back(); 
                t_flag=true; 
                //cout << "Removed Elem " << endl; 
            break; 
            
            case 3: 
                if(t_flag)
                {
                    m_last_max=f_GetMax(vec); 
                    t_flag=false; 
                }
                cout << m_last_max << endl;
            break; 
            
            default: 
                cout << "Error" << endl; 
        }
    }
    
    return 0;
}




