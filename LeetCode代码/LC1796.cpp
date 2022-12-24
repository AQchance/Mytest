#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int secondHighest(string s)
    {
        set<int> SET;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                SET.insert(s[i]);
        }
        if (SET.size() <= 1)
            return -1;
        auto tmp = SET.end();
        tmp--;
        tmp--;
        return *tmp - '0';
    }
};

int main()
{
    string s = "12345aaa65hdjkash";
    Solution sol;
    cout << sol.secondHighest(s) << endl;
    return 0;
}