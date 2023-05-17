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
    int pairSum(ListNode* head) {
        int mxsum = 0;
        int n = 0,i=0;
        
        ListNode* tmpNode;
        tmpNode = head;
        while(tmpNode!=NULL)
        {
            tmpNode = tmpNode->next;
            n++;
        }
        vector<int> v(n/2+1,0);
        tmpNode = head;
        while(tmpNode!=NULL)
        {
            int j = n-i-1;
            if(i<n/2)
            {
                v[i] += tmpNode->val;
                //cout<<i<<"I ";
            }
            else
            {
                v[j] += tmpNode->val;
                //cout<<j<<"X ";
            }
            tmpNode = tmpNode ->next;
            i++;
            
        }
       // cout<<"\n";
        for(auto x:v)mxsum = max(x,mxsum);
        return mxsum;
        
    }
};