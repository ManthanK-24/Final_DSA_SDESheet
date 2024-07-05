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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> ds;
        int cur = 0;
        
        ListNode* node = head;
        ListNode* prev = NULL;
        while(node!=NULL)
        {
             if(cur!=0)
             {
                 // MIN
                 if(node!=NULL && node->next!=NULL && 
                    node->val<prev->val && node->val<node->next->val)
                 {
                     ds.push_back(cur+1);
                 }
                 // MAX
                 if(node!=NULL && node->next!=NULL &&
                    node->val>prev->val && node->val>node->next->val)
                 {
                     ds.push_back(cur+1);
                 }
             }
            prev = node;
            node = node->next;
            cur++;
        }
        sort(ds.begin(),ds.end());
        int mx=-1;
        if(ds.size()>1)
        mx = ds[ds.size()-1]-ds[0];
        int mn = INT_MAX;
        for(int i=1;i<ds.size();i++)
        {
            mn = min(mn,ds[i]-ds[i-1]);
        }
        if(mn==INT_MAX)mn=-1;
        return {mn,mx};
    }
};