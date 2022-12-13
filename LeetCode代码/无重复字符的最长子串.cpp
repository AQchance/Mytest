#include<bits/stdc++.h>

using namespace std;
//Solution1总共用时36ms，beats 18%，Solution2总共用时小于1ms，beats 100%
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int MaxStr = 0;
        for (int i = 0; i < s.length(); i++) {
            while (ms.find(s[i]) != ms.end()) {
                ms.erase(s[left]);
                left++;
            }
            ms.insert(s[i]);
            if (MaxStr < ms.size()) MaxStr = ms.size();
        }
        return MaxStr;
    }
};

class Solution2 {
pubilc:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int cnt[128] = { 0 };
        int i, j, k = 0;
        for (i = 0, j = 0; i < len; i++) {
            while (cnt[s[i]] >= 1) {
                cnt[s[j]]--;
                j++;
            }
            cnt[s[i]]++;
            k = max(k, i - j + 1);
        }
        return k;
    }
};