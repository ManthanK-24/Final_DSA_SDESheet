class Solution {
public:
    int findDuplicate(vector<int>& ar) {
        
        int fast =ar[ar[0]] ,slow = ar[0];
        while(fast!=slow)
        {
            fast=ar[ar[fast]];
            slow = ar[slow];
        }
        slow = 0;
        while(fast!=slow)
        {
            fast = ar[fast];
            slow = ar[slow];
        }
        return fast;
    }
};