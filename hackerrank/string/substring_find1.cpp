/**
  * @brief Solution to Hackerrank Substring Find Problem 
  * @note https://www.hackerrank.com/challenges/two-strings/problem
  * - The goal is to check if 2 substrings has a common string but not to return the actual substring 
  * - This makes the actual problem much easier than it seems as a necessary and sufficient condition is they share a char so the proposed solution focuses on solving this equivalent challenge 
  * - It is implemented representing a string as an unordered_map of its chars (store O(1), loop O(N)) and then iterating over the other string looking up for each char in the other string (lookup O(1), loop O(N))
  */
#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) 
{
    unordered_set<char> temp; 
    for(const auto c : s1) temp.insert(c); 
    for(const auto c : s2) if( temp.find(c) != temp.end() ) return "YES"; 
    return "NO"; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}




