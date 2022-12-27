#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int minimumMoves(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'X')
            {
                ans++;
                i += 2;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s{"OOOOXXOOOXXXXXXOXOXOX"};
    cout << sol.minimumMoves(s) << endl;
    return 0;
}