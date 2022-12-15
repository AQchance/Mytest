// #include <iostream>
// #include <string>
// #include <cstring>
// #include <algorithm>

// using namespace std;

// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         int size = s.size();
//         while (size > 0)
//         {
//             for (int i = 0; i <= s.size() - size; i++)
//             {
//                 string s1=s.substr(i,size);
//                 bool flag=true;
//                 for(int j=0;j<size;j++){
//                     if(s1[j]!=s1[size-1-j]){
//                         flag=false;
//                         break;
//                     }
//                 }
//                 if(flag)
//                     return s1;
//             }
//             size--;
//         }
//         return s.substr(0, 1);
//     }
// };

// int main()
// {
//     string s = "aacabdkacaa";
//     Solution sol;
//     string mystring = sol.longestPalindrome(s);
//     cout << mystring << endl;
//     return 0;
// }

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

// 中心扩散法时间复杂度仅为O(n²)，优于暴力法（上面注释所示）

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int size = 1;
        string ans;
        int x=0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            // 最后要做越界检查
            for (int j = 1; i - j >= 0 && i + j < s.size(); j++)
            {
                if (s[i - j] == s[i + j])
                {
                    if (2 * j + 1 > size)
                    {
                        size = 2 * j + 1;
                        x=i-j;
                        size=2*j+1;
                    }
                }
                else
                    break;
            }
            if (s[i] != s[i + 1])
                continue;
            if (size < 2)
            {
                size = 2;
                x=i;
            }
            for (int k = i + 1, j = 1; i - j >= 0 && k + j < s.size(); j++)
            {
                if (s[i - j] == s[k + j])
                {
                    if (size < 2 * j + 2)
                    {
                        size = 2 * j + 2;
                        x=i-j;
                        size=2*j+2;
                    }
                }
                else
                    break;
            }
        }
        return s.substr(x,size);
    }
};

int main()
{
    string s = "aacabdkacaa";
    Solution sol;
    string mystring = sol.longestPalindrome(s);
    cout << mystring << endl;
    return 0;
}

// 上面的是中心扩散法，下面将使用动态规划的方法来解题

// #include <iostream>
// #include <string>
// #include <cstring>

// using namespace std;

// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         const int len = s.length();
//         string ans;
//         ans += s[0];
//         int size = 1;
//         bool dp[len][len];
//         memset(dp, false, sizeof(dp));
//         int x = 0; // 用于记录最终截取的指针
//         // 初始化dp数组
//         for (int i = 0; i < len; i++)
//         {
//             dp[i][i] = true;
//         }
//         for (int j = 1; j < len; j++)
//         {
//             for (int i = 0; i < j; i++)
//             {
//                 if (j - i == 1)
//                 {
//                     if (s[i] == s[j])
//                     {
//                         dp[i][j] = true;
//                         if (size < 2)
//                         {
//                             size = 2;
//                             x = i;
//                         }
//                     }
//                 }
//                 else
//                 {
//                     if (s[i] == s[j])
//                         dp[i][j] = dp[i + 1][j - 1];
//                     if (dp[i][j] == true && size < j - i + 1)
//                     {
//                         size = j - i + 1;
//                         x = i;
//                     }
//                 }
//             }
//         }
//         ans = s.substr(x, size);
//         return ans;
//     }
// };

// int main()
// {
//     string s = "aaaa";
//     Solution sol;
//     string mystring = sol.longestPalindrome(s);
//     cout << mystring << endl;
//     return 0;
// }