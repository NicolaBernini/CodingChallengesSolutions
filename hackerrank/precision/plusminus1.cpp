// Solution to 
// https://www.hackerrank.com/challenges/plus-minus

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    int t_wire_n; 
    int t_wire_tmp;
    int t_wire_pos=0; 
    int t_wire_neg=0; 
    int t_wire_zero=0; 
    cin >> t_wire_n; 
    //vector<int> t_stg_arr(t_wire_n); 
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    for(int t_wire_i=0; t_wire_i<t_wire_n; t_wire_i++) 
    {
        cin>>t_wire_tmp; 
        if(t_wire_tmp>0) t_wire_pos++; 
        if(t_wire_tmp<0) t_wire_neg++; 
        if(t_wire_tmp==0) t_wire_zero++; 
    }
    cout << setprecision(6) << ((float)t_wire_pos/t_wire_n) << std::endl;
    cout << setprecision(6) << ((float)t_wire_neg/t_wire_n) << std::endl;
    cout << setprecision(6) << ((float)t_wire_zero/t_wire_n) << std::endl; 
    return 0;
}
