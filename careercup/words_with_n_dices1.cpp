/**
  * @brief Solution the words with n dices 
  * 
  * Description 
  * 
  * Given a word of length n, and n six-sided dice with a character in each side, find out if this word is constructible by the set of given dice
  */

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Dice
{
	public: 
	Dice(const vector<char>& v) 
	{
		for(const auto& c : v) db.insert(c); 
	}
	
	bool is_member(const char c) const { return (db.find(c) != db.end()); }
	
	private: 
	unordered_set<char> db; 
}; 



bool solve( const vector<Dice>& v, const unordered_set<unsigned int>& exclude_list, const string& s )
{
	if(s=="") return true; 
	for(unsigned int i=0; i<v.size(); ++i) 
	{
		if(exclude_list.find(i) != exclude_list.end()) continue; 
		const auto d = v[i]; 
		const auto c = s[0]; 
		if(d.is_member(c))
		{
			auto temp = exclude_list; 
			temp.insert(i); 
			if( solve( v, temp, s.substr(1) ) ) return true; 
		}

	}
	return false; 
}

string show(const bool b) { return (b?"True":"False"); }

int main() {
	// your code goes here
	vector<Dice> v( {Dice({'a', 'b', 'c'}), Dice({'a', 'd', 'e'}), Dice({'g', 'l', 'm'}) } ); 
	vector<string> tests = {"adm", "ekg", "ecg"}; 
	for(const auto& t : tests) cout << show(solve(v, {}, t)) << endl; 
	
	return 0;
}


