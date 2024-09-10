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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* node = head;
         
        while(node->next!=NULL)
        {
            ListNode* nodeToBeInserted = new ListNode(__gcd(node->val,node->next->val));
        ListNode* tmp = node->next;
         node->next = nodeToBeInserted;
         nodeToBeInserted->next = tmp;
          node = tmp;
        }
        return head;
    }
};