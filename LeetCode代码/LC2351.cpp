#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution
{
public:
    char repeatedCharacter(string s)
    {
        set<char> myset;
        char ans;
        for (int i = 0; i < s.size(); i++)
        {
            if (myset.find(s[i]) != myset.end())
            {
                ans = s[i];
                break;
            }
            else
            {
                myset.insert(s[i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "abcdea";
    cout << sol.repeatedCharacter(s) << endl;
    return 0;
}