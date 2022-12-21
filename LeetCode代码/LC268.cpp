#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ans;
        const int n = nums.size();
        vector<bool> bl(n);
        for (int i = 0; i < n; i++)
        {
            bl[nums[i]] = true;
        }
        for (int i = 0; i < n; i++)
        {
            if (!bl[i])
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> a = {0, 2, 1};
    cout << sol.missingNumber(a) << endl;
    return 0;
}