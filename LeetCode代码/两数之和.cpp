#include<bits/stdc++.h>

using namespace std;
//只写函数
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = 0;
        map<int, int> Mymap;
        for (i = 0; i < nums.size(); i++) {
            if (Mymap.count(target - nums[i]) && i != Mymap[target - nums[i]]) return { i,Mymap[target - nums[i]] };
            else Mymap[nums[i]] = i;
        }
        return {};//论map容器的极好使用范例
    }
};