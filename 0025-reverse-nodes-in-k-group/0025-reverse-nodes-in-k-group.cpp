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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int count =0;
        while(cur!=NULL && count!=k)
        {
            cur = cur->next;
            count++;
        }
        if(count ==k)
        {
            cur = reverseKGroup(cur,k);
            while(count-- >0)
            {
                ListNode* nexNode = head->next;
                head->next = cur;
                cur = head;
                head = nexNode;
            }
            head = cur;
        }
        return head;
    }
};