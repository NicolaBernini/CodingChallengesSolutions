#include <iostream>
#include <vector>
using namespace std;

// remove_item :: [Int] -> Int -> [Int]
vector<int> remove_item (const vector<int>& a, const unsigned int id)
{
	vector<int> res; 
	for(unsigned int i=0; i<a.size(); ++i) if(i!=id) res.push_back(a[i]); 
	return res;
}


// add_item :: [Int] -> Int -> [Int]
vector<int> add_item(const vector<int>& a, const int b)
{
	vector<int> res=a; 
	res.push_back(b); 
	return res;
}

vector< vector<int> > merge(const vector< vector<int> >& a, const vector< vector<int> >& b)
{
	vector< vector<int> > res=a; 
	for(const auto& e : b) res.push_back(e); 
	return res;
}


// perm_comp :: [Int] -> [Int] -> [[Int]]
// Rel 1:N : at each layer, choose N parallel paths 
// Design 
// Complexity needs to be O(N!) = O(N*(N-1)...) so Recursive 
// State / Args 
// - Partial Items List 
// - Remaining Items List 
vector< vector<int> > permutations(const vector<int>& b, const vector<int>& a={})
{

	if(b.size()==0) return { a }; 
	
	vector< vector<int> > res; 
	for(unsigned int i=0; i<b.size(); ++i) res=merge(res, permutations(remove_item(b,i), add_item(a, b[i]))); 
	return res; 
}

int main() {
	// your code goes here
	
	auto res = permutations({1,2,3,4,5}); 
	cout << "Sol Num = " << res.size() << endl; 
	for(const auto& a : res) 
	{
		for(const auto& b : a) cout << to_string(b) << " "; 
		cout << endl; 
	}
	return 0;
}



