// Solution to 
// https://www.hackerrank.com/challenges/staircase?h_r=next-challenge&h_v=zen

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t_wire_n; 
    cin >> t_wire_n; 
    for(int t_wire_i=0; t_wire_i<t_wire_n; t_wire_i++) 
    {
        for(int t_wire_j=0; t_wire_j<(t_wire_n-t_wire_i)-1; t_wire_j++) cout << " "; 
        for(int t_wire_j=0; t_wire_j<t_wire_i+1; t_wire_j++) cout << "#"; 
        cout << std::endl; 
    }
    return 0;
}

