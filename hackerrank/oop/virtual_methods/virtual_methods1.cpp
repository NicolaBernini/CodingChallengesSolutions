
// Solution to 
// https://www.hackerrank.com/challenges/virtual-functions/problem


#include <string>

class Person
{
    public: 
    virtual void getdata() = 0;  ///< Required 
    virtual void putdata() = 0; 
    
    protected: 
    string name; 
    int age; 
    int cur_id; 
}; 


class Professor : public Person 
{
    public: 
    Professor() {Person::cur_id = gen_id; gen_id++;}
    virtual void getdata()
    {
        cin >> name; 
        cin >> age; 
        cin >> pubblications; 
    }
    
    virtual void putdata()
    {
        cout << name << " " << age << " " << pubblications << " " << cur_id << endl; 
    }
    
    private: 
    static int gen_id; 
    int pubblications; 
}; 

int Professor::gen_id = 1; 

class Student : public Person 
{
    public: 
    Student() {Person::cur_id = gen_id; gen_id++;}
    virtual void getdata()
    {
         int temp; 
         cin >> name; 
         cin >> age; 
         for(int i=0; i<6; ++i) { cin >> temp; marks.push_back(temp); }
    }
    
    virtual void putdata()
    {
       int temp=0; 
       for(const auto& e : marks) temp += e; 
       cout << name << " " << age << " " << temp << " " << cur_id << endl; 
    }
    
    private: 
    static int gen_id; 
    vector<int> marks; 
}; 

int Student::gen_id = 1; 


