#include <iostream>
#include <vector>
using namespace std;

vector<int> data = {1,2,3,3,3,3,3,4,5,6,7,8,8,9,9,9,10}; 

unsigned int find( const vector<int>& v, const unsigned int l, const unsigned int r, const int q )
{
	if(r==(l+1))
	{
		if(v[l]==q) return l+1; 
		if(v[r]==q) return r+1; 
		return 0; 
	}
	
	const auto m=(l+r)/2; 
  
	if(v[m]==q) return m+1; 
	if(q<v[m]) return find(v, l, m, q); 
	return find(v, m, r, q); 
}



unsigned int count(const vector<int>& v, const int q)
{
	unsigned int res=0; 
	const auto pos = find(v, 0, v.size()-1, q); 
	if(pos==0) return 0; 

	for(unsigned int i=pos-1; v[i]==q; i--) res++; 
	for(unsigned int i=pos; v[i]==q; i++) res++; 
	return res; 
}

int main() {

	int q = 9; 	
	cout << "Count " << q << " = " << count(data, q) << endl; 

	return 0;
}
