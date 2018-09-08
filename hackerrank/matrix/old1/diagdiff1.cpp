/**
  * @brief Solution to https://www.hackerrank.com/challenges/diagonal-difference
  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class matrix_t
{
    public: 
    uint32_t size; ///< Matrix Size 
    matrix_t(uint32_t in_size) : size(in_size), data(in_size, std::vector<int>(in_size)) {} ///< Initializing the Matrix with pased size appunto 
    
    int get(uint32_t r, uint32_t c)
    {
        return data[r][c]; 
    }
    
    void put(uint32_t r, uint32_t c, int val)
    {
        data[r][c] = val; 
    }
    
    int getLRDiagSum(void)
    {
        int sum=0; 
        for(uint32_t i=0; i<size; ++i)
        {
            //std::cout << "Adding Val " << get(i,i) << std::endl; 
            sum += get(i,i); 
        }

        return sum; 
    }
    
    int getRLDiagSum(void)
    {
        int sum=0; 
        for(uint32_t i=0; i<size; ++i)
            sum += get(size-i-1, i); 
        return sum; 
    }
    
    private: 
    std::vector< std::vector<int> > data; 
};


class db_t
{
    public: 
    int size; ///< Size read from Cmd Line 
    matrix_t* m; ///< Matrix is Dynamically Allocated once Size has been read 
};

class func_t
{
    public: 
    static void readLine(uint32_t size, uint32_t line, matrix_t* m)
    {
        int temp; 
        for(uint32_t i=0; i<size; ++i)
        {
            cin >> temp; 
            //std::cout << "Read Val " << temp << std::endl; 
            m->put(line, i, temp); 
            //std::cout << "Written Val " << m->get(line, i) << std::endl; 
        }
    }
    
    static void readMatrix(uint32_t size, matrix_t* m)
    {
        for(uint32_t i=0; i<size; ++i)
            readLine(size, i, m); 
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    db_t db; 
    
    cin >> db.size; 
    db.m = new matrix_t(db.size); 
    func_t::readMatrix(db.size, db.m); 
    //std::cout << "LR Sum " << db.m->getLRDiagSum() << std::endl; 
    //std::cout << "RL Sum " << db.m->getRLDiagSum() << std::endl; 
    std::cout << std::abs(db.m->getLRDiagSum() - db.m->getRLDiagSum()); 
    return 0;
}



