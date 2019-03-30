
// Original Link 
// https://www.hackerrank.com/challenges/new-year-chaos/problem

#include <bits/stdc++.h>
#include <set>

using namespace std;

vector<string> split_string(string);




///////////////////// SOLUTION START /////////////////////
/**
  * @brief Computing Min Bribes 
  * @note The real challenge is to avoid undercounting by looking only at the delta=(val - pos )
  * @note In all the cases where delta<2 it is possible that the actor received n bribes but also bribed zero or one and this is the cause for undercounting 
  * @note In order to identify this specific case, I check with respect to the elements on the left in the sequence 
  * @note More specifically, any hidden bribe is identified by the fact the number of elements on the left of the pivot and bigger than the pivot does not match with its delta 
  * @note However looking back at all the elements on the left of the pivot makes the complexity quadratic so even if it is a correct solution, it won't be able to scale well enough and fit into the limitations imposed by Hackerrank System 
  * @note That's why Dynamic Programming has been used: as we linearly observe the vector, we essentially perform and insert sort into an Ordered Set 
  * @note When we have a pivot (delta<2) instead of iterating over the input vector on [0..i] we iterate over the ordered set counting the Number bigger than the pivot condition and we break out of the loop as soon as we get an elemen that's smaller than the pivot (it's ordered)
  * @note This provides the right count for the hidden bribes which alongside the visible bribes provides the right total amount 
  */
void minimumBribes(vector<int> q) 
{
    unsigned int res=0; 
    
    // Used for Dynamic Programming Solution 
    // Remember the ordered list of numbers already observed 
    // The goal is to reduce the comlexity 
    std::set<unsigned int> d; 
    for(unsigned int i=0; i<q.size(); ++i)
    {
        d.insert(q[i]); 
        const int delta = q[i]-(i+1); 
        
        
        // With delta=2 no hidden bribes possible so only visible bribes so just count them 
        if(delta==2) 
        {
            res += delta; 
        }
        // Hidden bribes possible 
        else if(delta<2)
        {
            // Count the visible bribes 
            if(delta>0) res += delta; 
            
            unsigned int v=0; 
            
            // Ordered count, we get out as soon as smaller element is found 
            for(auto e = d.rbegin(); e != d.rend(); ++e)
            {
                if(*e > q[i]) v++; 
                if(v > abs(delta)) {res++; break;}
                if(*e < q[i]) break; 
            }
        }
        else if(delta>2)
        {
            cout << "Too chaotic" << endl; 
            return; 
        }
    }

    cout << res << endl; 
}

///////////////////// SOLUTION END //////////////////////////


int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}



