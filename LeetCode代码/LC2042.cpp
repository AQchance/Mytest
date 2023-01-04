#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
    bool areNumbersAscending(string s)
    {
        bool ans = true;
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] <= '9' && s[i] >= '0')
            {
                int sum = 0;
                for (; s[i] <= '9' && s[i] >= '0'; i++)
                {
                    sum *= 10;
                    sum += s[i] - '0';
                }
                if (q.empty())
                {
                    q.push(sum);
                }
                else
                {
                    if (sum > q.top())
                        q.push(sum);
                    else
                    {
                        ans = false;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "1 aaa 25 66 ssas";
    cout << sol.areNumbersAscending(s) << endl;
    return 0;
}