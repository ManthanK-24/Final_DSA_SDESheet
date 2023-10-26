
struct Node
{
    Node* links[2];
    
    bool containsKey(int bit)
    {
        return (links[bit]!= NULL);
    }
    Node* get(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node* node)
    {
        links[bit] = node;
    }
};

class Trie
{
   public:
     Node* root;
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
       Node* node = root;
       for(int i=31;i>=0;i--)
       {
           int bit = (num>>i) & 1;
           if( !node->containsKey(bit) )
           {
               node -> put(bit, new Node());
           }
           node = node -> get(bit);
       }
    }
    int getMax(int num)
    {
        Node* node = root;
        int mx = 0;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i) & 1;
            
            if(node->containsKey(1-bit) )
            {
                mx = mx | (1<<i);
                node = node->get(1-bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return mx;
    }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& qry) {
        vector<int> ans(qry.size(),0);
        vector<pair<int,pair<int,int>>> offlineQueries;
        int idx=0;
        for(int i=0;i<qry.size();i++)
        {
            offlineQueries.push_back({qry[i][1],{qry[i][0], idx++}});
        }
        sort(nums.begin(),nums.end());
        sort(offlineQueries.begin(),offlineQueries.end());
        int i=0;
        int n = nums.size();
        Trie trie;
        for(auto &it:offlineQueries)
        {
            while(i<n && nums[i]<=it.first)
            {
                trie.insert(nums[i]);
                i++;
            }
            if(i!=0) ans[it.second.second] = trie.getMax(it.second.first);
            else
                ans[it.second.second] = -1;
        }
        return ans;
    }
};