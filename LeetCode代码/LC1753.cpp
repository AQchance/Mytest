#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        priority_queue<int, vector<int>, less<int>> q;
        int ans = 0;
        q.push(a);
        q.push(b);
        q.push(c);
        while (q.top() > 0)
        {
            int e = q.top();
            q.pop();
            if (q.top() <= 0)
                break;
            int f = q.top();
            q.pop();
            ans++;
            q.push(e-1);
            q.push(f-1);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout<<sol.maximumScore(2,4,6)<<endl;
    return 0;
}