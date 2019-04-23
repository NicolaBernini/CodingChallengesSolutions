
#include <iostream>
#include <vector>
using namespace std;

vector<int> a = {5,6,7,8,9,10,11, 1,2,3,4};

unsigned int solve(const vector<int>& a, unsigned int l=0, unsigned int r=0)
{
    if(a.empty()) throw runtime_error("Empty"); 
    if(a.size()==1) return 0; 
    if(r==0) r=a.size()-1; ///< Overwrite the invalid initialization with the right value, unfortunately it is not possible to do this in function declaration 
    if(a[l] < a[r]) return l; ///< Sorted in Ascending Order 
    if(r-l==1) return r; 
    const auto m = (r+l)/2; 
    if(a[m] > a[l]) return solve(a, m, r); 
    return solve(a, l, m); 
}

int main() {
    // your code goes here
    cout << "Min=" << a[solve(a)]; 
    return 0;
}







