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

/**
  * @brief The Array Reading Function which sets the read element in the correct position since the beginning (avoiding actual rotation)
  * @tparam n_t Position in the Array Type 
  * @tparam e_t Element in the Array Type 
  * @tparam T The actual Container Type (STL Container for e_t type). Just a "push_back()" interface method is required 
  */
template <typename n_t, typename e_t, typename T>
void f_ReadArray(const n_t& n, const n_t& d, T& arr, std::function<n_t (n_t, n_t, n_t)> in_f_getpos){
    e_t temp; 
    for(n_t i=0; i<n; ++i)
    {
        cin >> temp; 
        arr[in_f_getpos(i, n, d)] = temp; 
    }
};

/**
  * @brief It computes the right position for each element taking the left rotation into account 
  * @tparam n_t Position Type 
  * @param [in] in_p The Initial Position 
  * @param [in] in_n The Array Length 
  * @param [in] in_d The Left Rotations 
  */
template <typename n_t>
n_t f_ComputePos(n_t in_p, n_t in_n, n_t in_d){
    if((in_d%in_n) <= in_p) return in_p - (in_d%in_n); 
    return (in_n - ((in_d%in_n)-in_p)); 
}; 


/**
  * @brief The Container Printing Function 
  * @tparam T The Container Type 
  * @taparm T_it The Iterator for the Container Type 
  */
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
    
    //** Reads the Array and Placing the Elements in the right position since the beginning 
    f_ReadArray<int_t, int_t, arr_t>(N, d, arr, std::bind(&f_ComputePos<int_t>,placeholders::_1,placeholders::_2, placeholders::_3)); 
    //** Prints the Container Result 
    f_ArrPrint<arr_t, arr_t::iterator>(arr); 

    
    return 0;
}




