/**
  * @brief Solution to https://www.hackerrank.com/challenges/compare-the-triplets?h_r=next-challenge&h_v=zen
  */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class params_t
{
    public: 
    int num_elem; 
    params_t() : num_elem(3) {}
}; 

class player_t
{
    public: 
    std::vector<int> elems; 
    int score; 
    
    player_t(int n) : elems(n), score(0) {}
}; 

class db_t
{
    public: 
    params_t params; 
    player_t a; 
    player_t b; 
    
    db_t() : a(params.num_elem), b(params.num_elem) {}
}; 

int main(){
    db_t db; 
    for(int i=0; i<db.params.num_elem; ++i)
        cin >> db.a.elems[i]; 
    for(int i=0; i<db.params.num_elem; ++i)
        cin >> db.b.elems[i]; 
    for(int i=0; i<db.params.num_elem; ++i)
    {
        if(db.a.elems[i] > db.b.elems[i]) db.a.score++; 
        if(db.a.elems[i] < db.b.elems[i]) db.b.score++;         
    }
    std::cout << db.a.score << " " << db.b.score; 
    return 0;
}
