/**
  * @brief Solution to the HR Problem of Sparse Array with no actual rotation but precomputation
  * @note Problem at https://www.hackerrank.com/challenges/array-left-rotation
  */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


#define READ(n) cin >> n

typedef uint64_t int_t; 

template <typename n_t, typename e_t, typename T>
void f_ReadArray(const n_t& n, const n_t& d, T& arr, std::function<n_t (n_t, n_t, n_t)> in_f_getpos){
    e_t temp; 
    for(n_t i=0; i<n; ++i)
    {
        cin >> temp; 
        arr[in_f_getpos(i, n, d)] = temp; 
    }
};

template <typename n_t>
n_t f_ComputePos(n_t in_p, n_t in_n, n_t in_d){
    if((in_d%in_n) <= in_p) return in_p - (in_d%in_n); 
    return (in_n - ((in_d%in_n)-in_p)); 
}; 


template <typename T, typename T_it>
void f_ArrPrint(T& arr){
    for(T_it it = arr.begin(); it != arr.end(); ++it) 
        cout << (*it) << " "; 
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int_t N; 
    int_t d; 
    READ(N); 
    READ(d); 
    
    typedef std::vector<int_t> arr_t; 
    
    arr_t arr(N); 
    
    f_ReadArray<int_t, int_t, arr_t>(N, d, arr, std::bind(&f_ComputePos<int_t>,placeholders::_1,placeholders::_2, placeholders::_3)); 
     f_ArrPrint<arr_t, arr_t::iterator>(arr); 

    
    return 0;
}




