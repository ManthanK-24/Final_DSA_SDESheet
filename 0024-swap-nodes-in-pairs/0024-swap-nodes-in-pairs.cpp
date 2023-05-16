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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* f=head;
        ListNode* s=NULL;
        if(head && head->next)
        s=head->next;
        if(!s)return head;
        ListNode* newHead = s;
        ListNode* prev;
        while(f && s)
        {
          ListNode* tmp = s->next;
          if(s!=newHead)
              prev->next=s;
          s->next = f;
          f->next = tmp;
          prev = f;
          f=f->next;
            if(f && f->next)
          s = f->next;
            else
                break;
        }
        return newHead;
    }
};