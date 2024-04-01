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
    ListNode* removeElements(ListNode* head, int x) {
        
        if(!head)return head;
        
        ListNode* node = head;
        ListNode* prev = head;
        
        while(node!=NULL)
        {
            if(node->val==x && node==head)
            {
                head = node->next;
                prev = head;
            }
            else if(node->val==x)
            {
                prev->next = node->next;
            }
            else
                prev = node;
            node = node->next;    
        }
        return head;
    }
};