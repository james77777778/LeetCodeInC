#include "leetcode.h"


// 1. find the two length of headA and headB
// 2. pull two linked list to the same length
// 3. check if there is intersection


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        int lenA = 0, lenB = 0;
        while(pA) {
            lenA ++;
            pA = pA->next;
        }
        while(pB) {
            lenB ++;
            pB = pB->next;
        }
        pA = headA; pB = headB;
        for(int i=0; i < lenA-lenB; i++)
            pA = pA->next;
        for(int i=0; i < lenB-lenA; i++)
            pB = pB->next;
        while(pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
        
    }
};