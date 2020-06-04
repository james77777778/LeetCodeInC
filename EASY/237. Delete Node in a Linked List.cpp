#include "leetcode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next = node->next;
        node->val = next->val;
        node->next = next->next;
        // cout << "why!!" << endl;
        // delete next;
    }
};


int main() {
    ListNode x4(9);
    ListNode x3(1, &x4);
    ListNode x2(5, &x3);
    ListNode x1(4, &x2);
    Solution s;
    s.deleteNode(&x2);
    ListNode* cur(&x1);
    while(cur!=nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}