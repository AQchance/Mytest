#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0)
            return 0;
        if (x == -2147483648)
            return 0;
            bool flag = true;
        if (x < 0)
        {
            flag = false;
            x = -x;
        }
        string s;
        while (x > 0)
        {
            s += x % 10 + '0';
            x /= 10;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != 0)
            {
                s = s.substr(i, s.size() - i);
                break;
            }
        }
        long ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ans *= 10;
            ans += s[i] - '0';
        }
        if (!flag)
            ans = -ans;
        if (ans > 2147483647 || ans < -2147483648)
            return 0;
        return ans;
    }
};

int main()
{
    int x=465132;
    Solution sol;
    cout<<sol.reverse(x)<<endl;
    return 0;
}