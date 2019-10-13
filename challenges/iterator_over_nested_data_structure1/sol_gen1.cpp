#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

enum class ElemType
{
	VAL, 
	DOWN, 
	UP, 
	NONE
}; 

template <typename T>
class Elem
{
	public: 
	Elem(): t(ElemType::VAL), val(0) {}
	Elem(const ElemType _t, const T _val): t(_t), val(_val) {}
	Elem(const ElemType _t) : Elem(_t, 0) {}
	
	ElemType t; 
	T val; 
}; 


template <typename T=int>
class MyDS
{
	public: 
	// Initialization Example: [1,2],3,[4,5],[], [6]
	MyDS(): v({{ElemType::DOWN}, {ElemType::VAL,1}, {ElemType::VAL,2}, {ElemType::UP}, {ElemType::VAL,3}, {ElemType::DOWN}, {ElemType::VAL,4}, {ElemType::VAL,5}, {ElemType::UP}, {ElemType::DOWN}, {ElemType::NONE}, {ElemType::UP}, {ElemType::DOWN}, {ElemType::VAL,6}, {ElemType::UP}}) {}
	
	vector< Elem<T> > v;
	
	string toStr() const 
	{
		stringstream res; 
		unsigned int curr_depth=0; 
		
		bool isComma=false; 
		for(const auto& e : v)
		{
			if(e.t == ElemType::DOWN) {res << (isComma?",":"") << "["; isComma=false;} 
			else if(e.t == ElemType::UP) {res << "]"; isComma=true; }
			else if(e.t == ElemType::VAL) {res << ( (isComma)?",":"" ) << e.val; isComma=true;} 
			else if(e.t == ElemType::NONE) {res << ""; isComma=true;} 
		}
		
		return res.str(); 
	}
}; 

template <typename T>
class MaybeMonad
{
	public: 
	MaybeMonad(const T& _data): isValid(true), data(_data) {}
	MaybeMonad() : isValid(false), data(0) {}
	
	const bool isValid; 
	const T data; 
	
	string toStr() const 
	{
		if(isValid) return to_string(data); 
		return ""; 
	}
}; 



template <typename T=int>
class Iterator
{
	public: 
	Iterator(const MyDS<T>& _d) : d(_d), index(0), n_vals(0), tot_n_vals(count()) {}
	
	bool hasNext() const
	{
		return n_vals<tot_n_vals; 
	}
	
	MaybeMonad<T> get()  
	{
		//MaybeMonad<T> res; 
		if(!is_index_valid) {is_index_valid=true; index=0;}
		else index++; 
		if(index == d.v.size()) throw runtime_error("No more elements"); 
		while( (d.v[index].t != ElemType::VAL) && (d.v[index].t != ElemType::NONE ) )
		{
			index++; 
			if(index == d.v.size()) throw runtime_error("No more elements"); 
		}
		
		n_vals++; 		
		if(d.v[index].t == ElemType::VAL) return MaybeMonad<T>(d.v[index].val); 
		index++; 
		return MaybeMonad<T>(); 
	}
	
	private: 
	
	// Just get the reference, do not copy it 
	const MyDS<T>& d; 
	
	bool is_index_valid; 
	unsigned int index; 
	unsigned int n_vals; 
	unsigned int tot_n_vals; 
	
	// O(N) loop to count the actual elements 
	unsigned int count() const 
	{
		unsigned int res=0; 
		for(const auto& e : d.v) res += ( (e.t == ElemType::VAL) || (e.t == ElemType::NONE) )?1:0; 
		return res; 
	}
}; 

int main() {
	// your code goes here
	MyDS<> d; 
	cout << d.toStr() << endl; 
	Iterator<> it(d); 
	while(it.hasNext()) cout << it.get().toStr() << ","; 
	cout << endl; 
	return 0;
}













