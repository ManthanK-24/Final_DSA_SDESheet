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
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        if(h1==NULL || h2==NULL)return NULL;
        
        ListNode* a = h1, *b=h2;
        while(a!=b)
        {
            a = a==NULL?h2:a->next;
            b = b==NULL?h1:b->next;
        }
        return a;
    }
};