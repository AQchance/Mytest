#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class Solution
{
public:
    string largestMerge(string word1, string word2)
    {
        int i = 0, j = 0;
        int len1 = word1.size();
        int len2 = word2.size();
        string ans;
        while (i < len1 && j < len2)
        {
            string a, b;
            a = word1.substr(i, len1 - i);
            b = word2.substr(j, len2 - j);
            if (a > b)
            {
                ans += a[0];
                i++;
            }
            else
            {
                ans += b[0];
                j++;
            }
        }
        ans += word1.substr(i, len1 - i);
        ans += word2.substr(j, len2 - j);
        return ans;
    }
};

int main()
{
    string word1 = "acddabe";
    string word2 = "abccaaa";
    Solution sol;
    cout << sol.largestMerge(word1, word2) << endl;
    return 0;
}