#include "leetcode.h"

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode* odd = head;
        ListNode* evenhead = head->next;
        ListNode* even = evenhead;
        // 1->2->3->4->5
        // 1st step:
        // odd(1)->2->3->4->5
        // even(2)->3->4->5
        // odd(1)->3->4->5
        // even(2)->4->5
        // 1->odd(3)->4->5
        // 2->even(4)->5
        // ...
        while(even != nullptr && even->next != nullptr) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};
