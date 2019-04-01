
// Original Link 
// https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem


#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;




/////////////////// SOLUTION ////////////////////

unordered_map< string, unordered_map<char, unsigned int> > data; 

bool is_equal(const unordered_map<char, unsigned int>* a, const unordered_map<char, unsigned int>* b)
{
    for(auto i=a->begin(); i!=a->end(); ++i)
    {
        const auto j = b->find(i->first); 
        if( (j==b->end()) || (i->second != j->second) ) return false; 
    }
    return true; 
}

unordered_map<char, unsigned int>* dict(const string& s)
{
    unordered_map<char, unsigned int> res; 
    auto temp = data.find(s); 
    if(temp!=data.end()) return &(temp->second); 

    // Compute 
    for(const auto& e : s) if(res.find(e)==res.end()) res[e]=1; else res[e]++; 
    data[s] = res; 
    return &(data[s]); 
}


// Complete the sherlockAndAnagrams function below.
// NOTES 
// - Substrings Computation is O(N^2) in String Size as there are 2 DoF both dependning on N : the 1) Substring Size and the 2) Substring Starting Pos
// - In this case, Substrings pairs of the same size need to be computed 
// - The best representation to perform anagram checking is as unordered set of characters hence using unordered_map to associtate to each char the number of times it is observed  
// - Comparing 2 dictionaries is easy : just iterate over one's keys and compare the related value with the same key value in the othe dictionary 
int sherlockAndAnagrams(string s) 
{
    int res=0; 

    // String -> ValidSizes(Int)
    for(unsigned int n=1; n<s.size(); ++n)
    {
        for(unsigned int i=0; i<s.size()-1; ++i)
        {
            for(unsigned int j=i+1; j<s.size(); ++j)
            {
                const auto d1 = dict(s.substr(i,n)); 
                const auto d2 = dict(s.substr(j,n)); 
                if(is_equal(d1,d2)) res++; 
            }
        }
    }
    return res; 
}



/////////////////////////////////////////////////////////////


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}



