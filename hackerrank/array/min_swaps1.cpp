
// Original Link 
// https://www.hackerrank.com/challenges/minimum-swaps-2/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);




///////////////// SOLUTION //////////////////

// Idea is to solve it with a recurrent function which iteratively performs greedy swaps 

void swap(vector<int>& v, const unsigned int a, const unsigned int b)
{
    int temp; 
    temp = v[a];
    v[a] = v[b]; 
    v[b] = temp; 
}

unsigned int search(const vector<int>& v, const unsigned int p, const int q)
{
    for(unsigned int i=p; i<v.size(); ++i) if(v[i] == q) return i; 
    throw std::runtime_error("Not Found"); 
}

int solve(vector<int>& v, const unsigned int i, const unsigned int cont)
{
    // Recursion Ending Conditions 
    if(i == v.size()-1) return cont; 

    // Expected Number 
    const int n = i+1; 
    if(v[i] == n) return solve(v, i+1, cont); 
    else 
    {
        const unsigned int j = search(v, i+1, n); 
        swap(v, i, j); 
        return solve(v, i+1, cont+1); 
    }
}

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    return solve(arr, 0, 0); 
}




/////////////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

    fout.close();

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
