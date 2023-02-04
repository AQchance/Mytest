#include <iostream>
#include <vector>

using namespace std;

// // 先试试暴力求解

// int calculate(int x, int y)
// {
//     vector<int> a, b;
//     for (int i = 0; x > 0; i++)
//     {
//         a.push_back(x % 2);
//         x /= 2;
//     }
//     for (int i = 0; y > 0; i++)
//     {
//         b.push_back(y % 2);
//         y /= 2;
//     }
//     int sum = 0;
//     if (a.size() <= b.size())
//     {
//         for (int i = 0; i < a.size(); i++)
//         {
//             if (b[i] == a[i])
//                 b[i] = 0;
//             else
//                 b[i] = 1;
//         }
//         for (int i = b.size() - 1; i >= 0; i--)
//         {
//             sum *= 2;
//             sum += b[i];
//         }
//     }
//     else
//     {
//         for (int i = 0; i < b.size(); i++)
//         {
//             if (b[i] == a[i])
//                 a[i] = 0;
//             else
//                 a[i] = 1;
//         }
//         for (int i = a.size() - 1; i >= 0; i--)
//         {
//             sum *= 2;
//             sum += a[i];
//         }
//     }
//     return sum;
// }

// class Solution
// {
// public:
//     int countPairs(vector<int> &nums, int low, int high)
//     {
//         int ans = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 if (calculate(nums[i], nums[j]) <= high && calculate(nums[i], nums[j]) >= low)
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };

// int main()
// {
//     Solution sol;
//     vector<int> nums = {1, 4, 2, 7};
//     cout << sol.countPairs(nums, 2, 6) << endl;
//     return 0;
// }

// 试试直接求解
// 还是超时，但是比上面的方法效率要高，下面尝试使用字典树

// class Solution {
// public:
//     int countPairs(vector<int>& nums, int low, int high) {
//         int ans=0;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 int a=nums[i]^nums[j];
//                 if(a<=high&&a>=low)
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };

// int main()
// {
//     Solution sol;
//     vector<int> nums = {1, 4, 2, 7};
//     cout << sol.countPairs(nums, 2, 6) << endl;
//     return 0;
// }

class Trie
{
public:
    vector<Trie *> children;
    int childrenNumber;
    Trie() : children(2), childrenNumber(0)
    {
        children[0] = children[1] = nullptr;
    }
    Trie insert(int x)
    {
        Trie *node = this;
        for (int i = 14; i >= 0; i--)
        {
            int y = (x >> i) & 1;
            if (node->children[y] == nullptr)
                node->children[y] = new Trie();
            node = node->children[y];
        }
    }
    int CountChildrenNumber(Trie *node)
    {
        if (node->children[0] == nullptr)
            return 0;
        if (node->children[1] == nullptr)
            return 0;
        node->childrenNumber = 1 + CountChildrenNumber(node->children[0]) + CountChildrenNumber(node->children[1]);
    }
    int getNumber(int x)
    {
        vector<int> index(15);
        for (int i = 14; i >= 0; i--)
        {
            index[14 - i] = (x >> i) & 1;
        }
        for(int i=0;i<15;i++){
            if(index[i]==1){
                
            }
        }
    }
};

class Solution
{
public:
    int countPairs(vector<int> &nums, int low, int high)
    {
        Trie tmp;
        for (int i = 0; i < nums.size(); i++)
        {
            tmp.insert(nums[i]);
        }
        tmp.CountChildrenNumber(tmp.children[0]);
        tmp.CountChildrenNumber(tmp.children[1]);
    }
};