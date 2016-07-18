#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

/**
  * @brief Recursive Lambda Function 
  * @note The `auto` keyword won't work for recursive 
  */
template <typename T>
function<int (const vector<T>& in_vec, const unsigned int i)> f_GetMax = [](const vector<T>& in_vec, const unsigned int i) -> T{
    if(i==0)
        return in_vec[i]; 
    
    T temp = f_GetMax<T>(in_vec, i-1); 
    if(in_vec[i] >= (temp))
        return in_vec[i]; 
    else 
       return temp; 
};


auto f_CreateVector = [](std::vector<int>& in_vec){
    in_vec.push_back(11); 
    in_vec.push_back(21); 
    in_vec.push_back(175); 
    in_vec.push_back(75); 
    in_vec.push_back(35); 
}; 

int main()
{
    std::vector<int> temp; 
    f_CreateVector(temp); 
    std::cout << "Max = " << f_GetMax<int>(temp, temp.size()-1); 
}
