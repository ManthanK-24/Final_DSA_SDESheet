class Solution {
public:
    int trap(vector<int>& ht) {
        
        int res = 0;
        int left = 0, right = ht.size()-1;
        int maxLeft = 0, maxRight = 0;
        while(left<=right)
        {
             if(ht[left]<=ht[right])
             {
                 if(ht[left]>maxLeft)maxLeft = ht[left];
                 else
                     res += maxLeft - ht[left];
                 left++;
             }
            else
            {
                if(ht[right]>maxRight)maxRight = ht[right];
                else
                    res+= maxRight - ht[right];
                right--;
            }
        }
        return res;
    }
};