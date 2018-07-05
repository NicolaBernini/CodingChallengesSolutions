

// Solution for 
// https://www.hackerrank.com/challenges/time-conversion/problem

#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


vector<string> explode(const string& s, const char c)
{
    istringstream iss(s); 
    vector<string> res; 
    for( string token; getline(iss, token, c ); ) res.push_back(token);
    return res; 
}

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) 
{
    stringstream res; 
    auto hhmmss = explode(s.substr(0,8), ':'); 
    int hh=stod(hhmmss[0]); 
    int mm=stod(hhmmss[1]); 
    int ss=stod(hhmmss[2]); 

    
    if( s.substr(8) == "AM" )
    {
        if(hhmmss[0]=="12") hh=0; 
        else hh = stod(hhmmss[0]); 
    }
    else if( s.substr(8) == "PM" )
    {
        if(hhmmss[0]=="12") hh=12; 
        else hh = 12+stod(hhmmss[0]); 
    }
    
    res << setfill('0') << setw(2) << hh << ":" << setfill('0') << setw(2) << mm << ":" << setfill('0') << setw(2) << ss; 
    return res.str(); 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}


