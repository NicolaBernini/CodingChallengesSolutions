// Solution to 
// https://www.hackerrank.com/challenges/mini-max-sum?h_r=next-challenge&h_v=zen


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define NUM 5

unsigned long int do_wire_Sum_Compute(const vector<int>& in_stg_arr, const int in_wire_exclude_id)
{
    unsigned long int t_wire_temp=0; 
    for(int t_wire_i=0; t_wire_i<NUM; t_wire_i++) if(t_wire_i != in_wire_exclude_id) t_wire_temp += in_stg_arr[t_wire_i]; 
    return t_wire_temp; 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> t_stg_arr(NUM); 
    unsigned long int t_stg_min;  
    unsigned long int t_stg_max; 
    unsigned long int t_wire_temp;
    // Loading 
    for(int t_wire_i=0; t_wire_i<NUM; t_wire_i++) cin >> t_stg_arr[t_wire_i]; 
    
    
    // Cases 
    t_wire_temp = do_wire_Sum_Compute(t_stg_arr, 0); 
    t_stg_min = t_wire_temp; 
    t_stg_max = t_wire_temp; 
    for(int t_wire_i=1; t_wire_i<NUM; t_wire_i++) 
    {
        t_wire_temp = do_wire_Sum_Compute(t_stg_arr, t_wire_i); 
        if(t_wire_temp<t_stg_min) {t_stg_min = t_wire_temp; }
        if(t_wire_temp>t_stg_max) {t_stg_max = t_wire_temp; }
    }
    cout << t_stg_min << " " << t_stg_max << std::endl; 
    
    return 0;
}



