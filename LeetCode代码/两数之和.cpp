#include<bits/stdc++.h>

using namespace std;
//ֻд����
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = 0;
        map<int, int> Mymap;
        for (i = 0; i < nums.size(); i++) {
            if (Mymap.count(target - nums[i]) && i != Mymap[target - nums[i]]) return { i,Mymap[target - nums[i]] };
            else Mymap[nums[i]] = i;
        }
        return {};//��map�����ļ���ʹ�÷���
    }
};