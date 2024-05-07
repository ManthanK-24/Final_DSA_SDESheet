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
    ListNode* rev(ListNode* node){
        ListNode* prev = NULL;
        while(node!=NULL)
        {
            ListNode* tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        if(head->val==0)return head;
        
        head = rev(head);
        int carry = 0;
        ListNode* node = head;
        while(node!=NULL)
        {
            int v = node->val*2 + carry;
            node->val = v%10;
            carry = v/10;
            if(node->next==NULL)break;
            node=node->next;
        }
        if(carry)
        {
            ListNode* last = new ListNode(carry);
            node->next = last;
        }
        head = rev(head);
        return head;
        
    }
};