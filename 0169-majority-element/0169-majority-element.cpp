class Solution {
public:
    int majorityElement(vector<int>& ar) {
        
        int major = ar[0], cnt = 1;
        for(int i=1;i<ar.size();i++)
        {
            if(cnt==0)
            {
                major = ar[i];
                cnt++;
            }
            else if(major == ar[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return major;
        
    }
};