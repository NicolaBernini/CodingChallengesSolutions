
// Source 
// https://www.hackerrank.com/challenges/cpp-maps/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int num; 
    int q; 
    string str; 
    int val; 
    map<string, int> state; 
    
    cin >> num; 
    for(int i=0; i<num; ++i)
    {
        cin >> q; 
        cin >> str; 
        if(q == 1) cin >> val; 
        
        switch(q)
        {
            case 1: 
                if(state.find(str) != state.end()) state[str] += val; 
                else state.insert(pair<string, int>(str, val)); 
            break; 
                
            case 2: 
                if(state.find(str) != state.end()) state.erase(str); 
            break; 
                
            case 3: 
                cout << state[str] << endl; 
            break; 
            
            default: 
            break; 
        }
        
        //cout << "Line (" << i << ") --> q=(" << q << "), str=(" << str << ") "; 
        //if(q==1) cout << "Val=(" << val << ")"; 
        //cout << endl; 
    }
    return 0;
}



