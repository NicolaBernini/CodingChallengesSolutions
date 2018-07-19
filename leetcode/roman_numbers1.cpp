
// Solution for 
// https://leetcode.com/problems/roman-to-integer/description/

class Solution {
public:
    int romanToInt(string s) {
        int temp=0; 
        for(int i=0; i<s.size(); ++i)
        {
            switch(s[i])
            {
                case 'M': 
                    temp += 1000; 
                break; 
                case 'D': 
                    temp += 500; 
                break; 
                case 'C': 
                    if(s[i+1]=='M') 
                    {
                        temp += 900;
                        i++;
                    }
                    else 
                    if(s[i+1]=='D') 
                    {
                        temp += 400;
                        i++;
                    }
                    else temp += 100; 
                break; 
                case 'L': 
                    temp += 50; 
                break; 
                case 'X': 
                    if(s[i+1]=='C') 
                    {
                        temp += 90;
                        i++;
                    }
                    else 
                    if(s[i+1]=='L') 
                    {
                        temp += 40;
                        i++;
                    }
                    else temp += 10; 
                break; 
                case 'V': 
                    temp += 5; 
                break; 
                case 'I': 
                    if(s[i+1]=='X') 
                    {
                        temp += 9;
                        i++;
                    }
                    else 
                    if(s[i+1]=='V') 
                    {
                        temp += 4;
                        i++;
                    }
                    else temp += 1; 
                break;                     
            }
        }
        return temp; 
    }
};

