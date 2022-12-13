// #include <iostream>
// #include <string>
// #include <set>
// #include <map>
// #include <vector>

// using std::string;
// using namespace std;

// const int N=26;

// class Solution
// {
// public:
//     int beautySum(string s)
//     {
//         int window_size = 2;
//         int sum = 0;
//         int length = s.size();
//         while (window_size <= length)
//         {
//             for (int i = 0; i <= length - window_size; i++)
//             {
//                 std::map<char, int> m_map;
//                 for (int j = i; j < i + window_size; j++)
//                 {
//                     if(m_map.find(s[j])==m_map.end())
//                         m_map[s[j]]=1;
//                     else m_map[s[j]]++;
//                 }
//                 // 下面寻找最大值和最小值
//                 int max_count = -1, min_count = 100000000;
//                 for (auto tmp = m_map.begin(); tmp != m_map.end(); tmp++)
//                 {
//                     if (tmp->second > max_count)
//                         max_count = tmp->second;
//                     if (tmp->second < min_count)
//                         min_count = tmp->second;
//                 }
//                 sum += max_count - min_count;
//             }
//             window_size++;
//         }
//         return sum;
//     }
// };

// int main()
// {
//     string s = "aabcbaa";
//     Solution sol;
//     std::cout << sol.beautySum(s) << std::endl;
//     return 0;
// }
/*
上面的也是暴力算法，但是缺少了循环的重复利用性
下面的则要更快一些
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int beautySum(string s)
    {
        int sum = 0;
        int length = s.size();
        for (int i = 0; i < length; i++)
        {
            std::vector<int> a(26);
            for (int j = i; j < length; j++)
            {
                int max_cnt = 0;
                int min_cnt = 600;
                a[s[j] - 'a']++;
                for (int k = 0; k < 26; k++)
                {
                    if (a[k] != 0)
                    {
                        max_cnt = max(a[k], max_cnt);
                        min_cnt = min(a[k], min_cnt);
                    }
                }
                sum += max_cnt - min_cnt;
            }
        }
        return sum;
    }
};

int main()
{
    string s = "aabcbaa";
    Solution sol;
    std::cout << sol.beautySum(s) << std::endl;
    return 0;
}
