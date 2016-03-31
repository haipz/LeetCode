/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int, int> mm;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i]) mm.insert(make_pair(lists[i]->val, i));
        ListNode *head = NULL, *tail = NULL;
        while (!mm.empty()) {
            int i = mm.begin()->second;
            mm.erase(mm.begin());
            if (head == NULL) head = tail = lists[i];
            else tail = tail->next = lists[i];
            lists[i] = lists[i]->next;
            if (lists[i] != NULL) mm.insert(make_pair(lists[i]->val, i));
        }
        return head;
    }
};
