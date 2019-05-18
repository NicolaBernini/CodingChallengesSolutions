#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


// pos = Internal Map with (val, [pos]) association 
// count = Internal Map with (val, count) association 
// Loop1: Copying Values in Map 
// IF1 = Checks if the values is first observed 
/// C1 = First observed 
/// C2 = More than once observed 
// temp = Possible container for already obs values 
unordered_map< long, vector<long> > build_map(const vector<long> arr)
{
    unordered_map< long, vector<long> > pos; 
    // Loop1 
    for(unsigned int i=0; i<arr.size(); ++i) 
    {
        auto temp = pos.find(arr[i]); 
        // IF1
        if(temp == pos.end()) pos[arr[i]] = {i}; ///< C1
        else temp->second.push_back(i); ///< C2
    }
    return pos; 
}

// Complete the countTriplets function below.
// res = Result so Number of Triplets found 
// Loop2: Seeing all initial values 
// Loop3: All the positions of a valid element 
// i = Index of the first elem (guaranteed to exist)
// _j = Iterator to the second elem (not guaranteed to exist) 
// _k = Iterator to the third elem (not guaranteed to exist)
// IF1 = If second elem is not found, skip to the next first elem 
// IF2 = If third elem is not found, skip to the next first elem 
// Loop4 = Goes over the possible j 
// IF3 = Checks i,j order vinculus 
// Loop5 = Goes over the possible k 
// IF4 = Checks j,k order vinculus 
long countTriplets(vector<long> arr, long r) 
{
    long res=0; 
    auto pos = build_map(arr); 

    if(r==1)
    {
        for(const auto& e : pos)
        {
            const auto n = e.second.size(); 
            if(n > 2) res += n*(n-1)*(n-2)/6; 
        }
        return res; 
    }

    // Loop2 
    //for(unsigned int i=0; i<arr.size(); ++i) 
    for(const auto& _v : pos)
    {
        auto v = _v.first; 
        auto _j = pos.find(v*r); 
        // IF1
        if(_j == pos.end()) continue; 
        auto _k = pos.find(v*r*r); 
        // IF2
        if(_k == pos.end()) continue; 
        
        // Loop3 
        for(auto i=_v.second.begin(); i!=_v.second.end(); ++i)
        {
            bool has_changed=false; 
            // Loop4 
            for(auto j=_j->second.rbegin(); j!=_j->second.rend(); ++j) 
            {
                // IF3
                if((*i) < (*j))
                {
                    // Loop5 
                    for(auto k=_k->second.rbegin(); k != _k->second.rend(); ++k)
                    {
                        // IF4 
                        if((*j) < (*k)) 
                        {
                            res++; 
                            has_changed = true; 
                        }
                        else break; 
                    }
                } else break; 
            }
            if(! has_changed) break; 
        }

    }
    return res; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
