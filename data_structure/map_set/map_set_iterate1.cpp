/**
  * @brief Verify both the unordered_set and set iterability 
  * 
  * - In addition to the lookup semantic they also provide an iterable semantic 
  * - In case of set, it is ordered according to the operator< () definition hence by default it is ascending 
  * - In case of unordered_set there is no order guarantee 
  */ 

#include <iostream>
#include <unordered_set>
#include <set>

#include <vector>
#include <string>

using namespace std;

template <typename T>
string to_str(const T& a)
{
	string res="";
	for(auto i=a.begin(); i!=a.end(); ++i) res += to_string(*i) + " "; 
	return res; 
}

int main() {
	// your code goes here
	unordered_set<int> a; 
	set<int> c; 
	
	const vector<int> t({11, 5, 22, 6, 90}); 
	for(const auto& e : t) 
	{
		a.insert(e); 
		c.insert(e); 
	}


	cout << "A = " << to_str(a) << endl; 
	cout << "C = " << to_str(c) << endl; 
	
	
	return 0;
}











