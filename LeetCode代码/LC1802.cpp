#include <iostream>

using namespace std;

class Solution
{
public:
    int maxValue(int n, int index, int maxSum)
    {
        int left = 1, right = maxSum;
        int ans;
        while (left <= right)
        {
            long mid = (left + right) / 2;
            long sum = 0;
            if (mid <= index + 1)
            {
                sum += index + 1 - mid;
                sum += (1 + mid) * mid / 2;
            }
            else
            {
                sum += (index + 1) * (mid + mid - index)/2;
            }
            int j = n - index;
            sum -= mid;
            if (j > 0)
            {
                if (mid <= j)
                {
                    sum += j - mid;
                    sum += (mid + 1) * mid / 2;
                }
                else
                {
                    sum += j * (mid + mid - j + 1)/2;
                }
            }
            if (sum > maxSum)
            {
                right = mid - 1;
            }
            else
            {
                ans = mid;
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.maxValue(4, 2, 6) << endl;
    return 0;
}