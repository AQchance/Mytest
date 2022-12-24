#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int ans = 0;
        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i][0] == '+')
                ans++;
            else if (operations[i][0] == '-')
                ans--;
            else
            {
                if (operations[i][1] == '+')
                    ans++;
                else
                    ans--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> a{"++X", "--X", "X++"};
    cout << sol.finalValueAfterOperations(a) << endl;
    return 0;
}