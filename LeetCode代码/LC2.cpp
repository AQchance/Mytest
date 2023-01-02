#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //做类似的相加类问题设置一个进位位是极为方便的
    //舍不得定义一个进位位那就像我一样被强迫症压迫到难受死
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode;
        l3->next = 0;
        auto temp = l3;
        int c = 0, i, j;
        while (1) {
            if (l1 != 0) {
                i = l1->val;
                l1 = l1->next;
            }
            else i = 0;
            if (l2 != 0) {
                j = l2->val;
                l2 = l2->next;
            }
            else j = 0;
            ListNode* p = new ListNode;
            if (i == 0 && j == 0 && c == 0 && l1 == 0 && l2 == 0) {
                if (l3->next == 0) {
                    l3->val = 0;
                    return l3;
                }
                else return l3->next;
            }
            p->val = (i + j + c) % 10;
            p->next = 0;
            temp->next = p;
            temp = p;
            c = (i + j + c) / 10;
        }
        return l3->next;
    }
};