
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<int> a = {5,6,7,8,9,10,11, 1,2,3,4};

vector<int>::iterator solve(const vector<int>::iterator l, const vector<int>::iterator r)
{
    if(l==r) return r; ///< Covers the single element array case 
    if(*l < *r) return l; ///< Sorted in Ascending Order 
    if(r-l==1) return r; 
    const auto m = l + distance(l,r)/2;  
    if(*m > *l) return solve(m, r); 
    return solve(l, m); 
}

int main() {
    // your code goes here
    cout << "Min=" << *solve(a.begin(), a.end()-1); 
    return 0;
}








