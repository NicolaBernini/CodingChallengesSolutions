/**
  * @brief Solution to https://www.hackerrank.com/challenges/a-very-big-sum?h_r=next-challenge&h_v=zen
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
    long int sum=0; 
    long int temp=0; 
    for(int arr_i = 0;arr_i < n;arr_i++){
       //cin >> arr[arr_i];
        cin >> temp; 
        sum += temp;
    }
    std::cout << sum; 
    return 0;
}

