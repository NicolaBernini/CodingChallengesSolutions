#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// Complete the substrCount function below.
long substrCount(int n, const string& s) 
{
    long res=0; 
    long int d[3] = {0,0,0}; 
    for(unsigned int i=1; i<s.size(); ++i)
    {
        if(s[i] != s[d[2]])
        {
            // Adding T1
            const auto l1=(i-d[2]); 
            const auto add_l1 = l1*(l1+1)/2; 
            res += add_l1;

            // Adding T2 
            if( (d[2] > d[1]) && (d[1] > d[0]) && (d[2]-d[1]==1) && (s[d[2]] != s[d[1]]) && (s[d[2]] == s[d[0]]) ) 
            {
                const auto l2 = min(i - d[2], d[1] - d[0]); 
                const auto add_l2 = l2; 
                res += add_l2; 
            }

            d[0] = d[1]; d[1] = d[2]; d[2] = i; 
        }
    }

    return res; 

}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);
    
    // NOTE: Changed also this part for convenience 
    long result = substrCount(n, s+'0');

    fout << result << "\n";

    fout.close();

    return 0;
}



