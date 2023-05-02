class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int neg = 0, zer = 0, pos = 0;
        for(auto& x:nums)
        {
            if(x<0)neg++;
            else if(x>0)pos++;
            else zer++;
        }
        if(zer)return 0;
        
        if(neg){
            if(neg%2)return -1;
        }
        return 1;
        
    }
};