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

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            // Return the last node.
            return head;
        }
        ListNode* reversedhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return reversedhead;
    }


    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head, *prev = NULL, ptr = *head;
        while (cur) {
            ListNode* pnext =  cur->next;
            cur->next = prev;
            prev = cur;
            cur = pnext;

        }
        return prev;
    }
};