#include "leetcode.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* preN = head;
        ListNode* nextN = preN;
        for(int i=0; i<n; i++)
            nextN = nextN->next;
        // check if n-th node is head
        if(nextN == nullptr) 
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        // find n-th node from end
        while(nextN->next != nullptr) {
            preN = preN->next;
            nextN = nextN->next;
        }
        // remove n-th node
        ListNode* tmp = preN->next;
        // check n-th node is tail
        if(tmp == nullptr)
            preN->next = nullptr;
        else {
            preN->next = tmp->next;
            delete tmp;
        }
        return head;
    }
};


int main() {
    ListNode head_dummy(0);
    ListNode *head_p = &head_dummy;
    for(int i=1; i<5; i++) {
        head_p->next = new ListNode(i);
        head_p = head_p->next;
    }

    Solution sol;
    ListNode* res = sol.removeNthFromEnd(head_dummy.next, 1);
    while(res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}