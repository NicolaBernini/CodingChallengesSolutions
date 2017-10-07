// Solution to 
// https://www.hackerrank.com/challenges/birthday-cake-candles

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t_wire_n; 
    int t_wire_tallest_id=0; 
    int t_wire_tallest_num=0;
    int t_wire_temp; 
    cin >> t_wire_n; 
    for(int t_wire_i=0; t_wire_i<t_wire_n; t_wire_i++) 
    {
        cin >> t_wire_temp; 
        if(t_wire_temp > t_wire_tallest_id)
        {
            t_wire_tallest_id=t_wire_temp; 
            t_wire_tallest_num=1; 
        }
        else if(t_wire_temp==t_wire_tallest_id) t_wire_tallest_num++; 
    }
    cout << t_wire_tallest_num << std::endl; 
    return 0;
}


