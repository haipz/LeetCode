/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0), *cur = &head;
        int tmp = 0;
        while (l1 || l2 || tmp) {
            tmp += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            cur = cur->next = new ListNode(tmp % 10);
            tmp /= 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head.next;
    }
};
