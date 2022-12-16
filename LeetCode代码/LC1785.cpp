#include <iostream>
#include <vector>

using namespace std;

// 主要是因为溢出导致正确率低，所以才放到了中等难度？
// 解题之前需要注意范围是否超过数据结构的存储范围

class Solution
{
public:
    int minElements(vector<int> &nums, int limit, int goal)
    {
        long long ans = 0;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        ans = goal - sum;
        if (ans == 0)
            return 0;
        else if (ans < 0)
            ans = -ans;
        if (ans % limit != 0)
            return ans / limit + 1;
        else
            return ans / limit;
    }
};

int main()
{
    vector<int> nums(4);
    nums[0] = 1;
    nums[1] = -10;
    nums[2] = 1;
    nums[3] = 9;
    int goal = 0;
    int limit = 100;
    Solution sol;
    int ans = sol.minElements(nums, limit, goal);
    cout << ans << endl;
    return 0;
}