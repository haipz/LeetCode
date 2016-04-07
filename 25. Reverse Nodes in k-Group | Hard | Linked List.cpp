/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
*/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode newhead(0), *p = &newhead;
        newhead.next = head;
        while (p) {
            ListNode *kth = p, *newp = p->next;
            for (int i = 0; i < k; ++i)
                if (kth) kth = kth->next;
            if (!kth) break;
            ListNode *p1 = p->next, *p2 = p1->next;
            p1->next = kth->next;
            for (int i = 1; i < k; ++i) {
                ListNode *tp = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = tp;
            }
            p->next = kth;
            p = newp;
        }
        return newhead.next;
    }
};
