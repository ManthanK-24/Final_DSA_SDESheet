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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* leftNode = head;
        int sum = 0;
        leftNode = leftNode->next;
        
        ListNode* rightNode = leftNode;
        while(rightNode!=NULL)
        {
            sum += rightNode->val;
            if(rightNode->val==0)
            {
                leftNode->val = sum;
                sum = 0;
                if(rightNode->next!=NULL)
                leftNode->next =rightNode;
                else
                leftNode->next = NULL;
                
                leftNode = rightNode;
                
            }
            rightNode = rightNode->next;
        }
        return head->next;
    }
};