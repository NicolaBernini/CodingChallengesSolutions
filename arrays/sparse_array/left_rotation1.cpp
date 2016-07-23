/**
  * @brief Solution to the HR Problem of Sparse Array with actual rotation 
  * @note Problem at https://www.hackerrank.com/challenges/array-left-rotation
  */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

typedef uint64_t int_t; 
#define READ(n) cin >> n

template <typename n_t, typename e_t, typename T>
void f_ReadArray(const n_t& n, T& arr){
    e_t temp; 
    for(n_t i=0; i<n; ++i)
    {
        cin >> temp; 
        arr.push_back(temp); 
    }
};

template <typename T>
void f_ShiftLeft(T& arr){
    arr.push_back(arr[0]); 
    arr.pop_front(); 
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
    
    typedef std::deque<int_t> arr_t; 
    arr_t arr; 
    
    //** Load Array as it is 
    f_ReadArray<int_t, int_t, arr_t>(N, arr); 
    
    //** Perform rotations 
    for(int_t i=0; i<d; ++i) f_ShiftLeft<arr_t>(arr); 
    
    //** Print Results 
    f_ArrPrint<arr_t, arr_t::iterator>(arr); 
    
    return 0;
}




