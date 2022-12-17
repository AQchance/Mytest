#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int p1 = 0, p2, n = nums.size();
        for (vector<int>& g : groups) {
            p2 = 0;
            while (p2 < g.size() && p1 < n) {
                if (nums[p1++] == g[p2]) p2++;
                else {p1 -= p2; p2 = 0;} 
            }
            if (p1 >= n && p2 != g.size()) return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}

