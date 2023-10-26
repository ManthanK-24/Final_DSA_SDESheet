struct Node{
    Node* links[2];
    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
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
class Trie{
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
            int bit = (num >> i) & 1;
            if( !node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num)
    {
        int mx = 0;
        Node* node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i) & 1;
            if( node->containsKey(1-bit) )
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
    int findMaximumXOR(vector<int>& nums) {
        Trie trieDS;
        for(auto x:nums)trieDS.insert(x);
        int mx = 0;
        
        for(auto x:nums)
        {
            mx = max(mx,trieDS.getMax(x));
        }
        return mx;
    }
};