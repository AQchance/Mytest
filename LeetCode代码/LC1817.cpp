#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

// 仅仅排序，没有去重，击败5%，只能说是提供了一种思路吧，效率不大行，快要超时了。
class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {
        vector<int> answer(1000001);
        sort(logs.begin(), logs.end(), cmp);
        set<int> myset;
        for (int i = 0; i < logs.size(); i++)
        {
            myset.insert(logs[i][1]);
            if (i == logs.size() - 1)
            {
                answer[myset.size()]++;
                myset.clear();
                break;
            }
            else if (logs[i][0] != logs[i + 1][0])
            {
                answer[myset.size()]++;
                myset.clear();
            }
        }
        auto iter1 = answer.begin() + 1;
        auto iter2 = answer.begin() + k + 1;
        vector<int> myanswer(iter1, iter2);
        return myanswer;
    }
};

int main()
{
    Solution sol;
    int k = 5;
    vector<vector<int>> logs{
        {0, 5}, {1, 2}, {0, 2}, {0, 5}, {1, 3}};
    vector<int> answer;
    answer = sol.findingUsersActiveMinutes(logs, k);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " " << endl;
    }
    return 0;
}