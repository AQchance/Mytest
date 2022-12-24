#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
            {
                ans += nums[i] - nums[i + 1] + 1;
                nums[i + 1] += nums[i] - nums[i + 1] + 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> a = {1, 1, 1};
    Solution sol;
    cout << sol.minOperations(a);
    return 0;
}