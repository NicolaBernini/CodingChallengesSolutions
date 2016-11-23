/**
  * @brief Solution of Exercise at https://www.hackerrank.com/challenges/simple-array-sum?h_r=next-challenge&h_v=zen
  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    //vector<int> arr(n);
    int sum=0; 
    int temp=0; 
    for(int arr_i = 0;arr_i < n;arr_i++){
        cin >> temp; 
        sum += temp;
       //cin >> arr[arr_i];
    }
    std::cout << sum; 
    return 0;
}
