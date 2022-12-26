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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head, *slow = head;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast) // odd case: let right half smaller
        {
            slow = slow ->next;
        }
        slow = reverse(slow);
        fast = head;
        while(slow!=NULL)
        {
            if(fast->val!=slow->val)return 0;
            fast = fast->next;
            slow = slow->next;
        }
        return 1;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        while(head)
        {
            ListNode* nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        return prev;
    }
};