#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 一个单调递减一个单调递增，采用二分求交点
class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int left = 1;
        int ans;
        int right = *max_element(nums.begin(), nums.end());
        while (left <= right)
        {
            int y = (left + right) / 2;
            int opt = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                opt += (nums[i] - 1) / y;
            }

            if (opt < maxOperations)
            {
                ans = y;
                right = y-1;
            }
            else if (opt > maxOperations)
            {
                left = y + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> a = {431, 922, 158, 60, 192, 14, 788, 146, 788, 775, 772, 792, 68, 143, 376, 375, 877, 516, 595, 82, 56, 704, 160, 403, 713, 504, 67, 332, 26};
    int n = 80;
    cout << sol.minimumSize(a, n) << endl;
    return 0;
}