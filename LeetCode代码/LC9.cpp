#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        else {
            string s1, s2;
            while (x > 0) {
                s1 += x % 10;
                x /= 10;
            }
            s2 = s1;
            reverse(s1.begin(), s1.end());
            if (s2 == s1) return true;
            return false;
        }
    }
};/*֮����ʹ��string�������ֱ��������ȥ������Ϊstring��
  ���ᱻ���������ƣ���int����long���������Եĳ��ȱ׶�*/