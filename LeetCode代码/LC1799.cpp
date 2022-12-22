#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>

using namespace std;

// GCD 为创建的数据结构，用来保存计算后的最大公约数以及两数的index
class GCD
{
public:
    int cn2;
    vector<int> v;
};

bool cmp(GCD a, GCD b)
{
    return a.cn2 > b.cn2;
}

class Solution
{
public:
    int maxScore(vector<int> &nums)
    {
        const int n = nums.size();
        vector<GCD> gcd(n * (n - 1) / 2);
        vector<bool> flag(n);         // 用来保存一个数是否用过
        vector<int> calculate(n / 2); // 保存最终用来计算的数
        int ans = 0;
        for (int i = 0, k = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                gcd[k].cn2 = __gcd(nums[i], nums[j]);
                gcd[k].v.push_back(i);
                gcd[k].v.push_back(j);
                k++;
            }
        }
        sort(gcd.begin(), gcd.end(), cmp);
        for (int i = 0, k = 0; i < gcd.size(); i++)
        {
            int x = gcd[i].v[0];
            int y = gcd[i].v[1];
            if (flag[x] == false && flag[y] == false)
            {
                calculate[k++] = gcd[i].cn2;
                flag[x] = true;
                flag[y] = true;
            }
        }
        for (int i = 0; i < n / 2; i++)
        {
            ans += (n / 2 - i) * calculate[i];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> a = {415,230,471,705,902,87};
    cout << sol.maxScore(a) << endl;
    return 0;
}