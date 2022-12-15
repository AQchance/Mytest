#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Solution
{
public:
    string calculate(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            sum += s[i] - '0';
        }
        string result;
        while (sum > 0)
        {
            result += sum % 10 + '0';
            sum /= 10;
        }
        string result1;
        for (int i = result.size() - 1; i >= 0; i--)
        {
            result1 += result[i];
        }
        return result1;
    }
    int getLucky(string s, int k)
    {
        string mystring;
        int a;

        for (int i = 0; i < s.size(); i++)
        {
            a = s[i] - 'a' + 1;
            if (a > 9)
            {
                mystring += a / 10 + '0';
                mystring += a % 10 + '0';
            }
            else
                mystring += a + '0';
        }
        for (int i = 0; i < k - 1; i++)
        {
            mystring = calculate(mystring);
        }

        int sum = 0;
        for (int i = 0; i < mystring.size(); i++)
        {
            sum += mystring[i] - '0';
        }
        return sum;
    }
};

int main()
{
    string s = "leetcode";
    int k = 2;
    Solution sol;
    int i = sol.getLucky(s, k);
    cout << i << endl;
}