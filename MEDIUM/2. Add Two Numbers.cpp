#include "leetcode.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        int sum = 0;
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr || carry) {
            sum = (l1!=nullptr? l1->val: 0) + (l2!=nullptr? l2->val: 0) + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            l1 = l1!=nullptr? l1->next: l1;
            l2 = l2!=nullptr? l2->next: l2;
        }
        return dummy.next;
    }
};


int main() {
    ListNode l1_dummy(0);
    ListNode *l1_p = &l1_dummy;
    for(int i=2; i<5; i++) {
        l1_p->next = new ListNode(i);
        l1_p = l1_p->next;
    }

    ListNode l2_dummy(0);
    ListNode *l2_p = &l2_dummy;
    for(int i=1; i<6; i+=2) {
        l2_p->next = new ListNode(i);
        l2_p = l2_p->next;
    }

    Solution sol;
    ListNode *res = sol.addTwoNumbers(l1_dummy.next, l2_dummy.next);
    while(res!=nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}