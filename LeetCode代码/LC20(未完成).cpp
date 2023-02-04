#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> mystack;
        mystack.push(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            if (abs(s[i] - mystack.top()) == 1 || abs(s[i] - mystack.top()) == 2){
                mystack.pop();
            }
            else{
                mystack.push(s[i]);
            }
        }
        if(mystack.empty()) 
            return true;
        else 
            return false;
    }
};