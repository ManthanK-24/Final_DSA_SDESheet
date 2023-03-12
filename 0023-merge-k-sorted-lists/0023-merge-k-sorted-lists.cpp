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
    ListNode* mergeKLists(vector<ListNode*>& vl) {
        
        if(vl.size()==0)return NULL;
        priority_queue<pair<int,ListNode*>> pq;
        
        for(int i=0;i<vl.size();i++)
        {
            while(vl[i]!=NULL)
            {
                pq.push({-vl[i]->val,vl[i]});
                vl[i] = vl[i]->next;
            }
        }
        
        if(pq.empty())return NULL;
        
        ListNode* head;
        ListNode* itr;
        
        head = pq.top().second;
        itr = pq.top().second;
        while(!pq.empty())
        {
            itr->next = pq.top().second;
            itr = pq.top().second;
           
            pq.pop();
        }
        itr->next = NULL;
        return head;
    }
};