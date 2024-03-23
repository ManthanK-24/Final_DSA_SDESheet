class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> lft(n,0),rgt(n,0);
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            if(i>0)
            {
                lft[i] = sum - nums[i];
            }
        //    cout<<i<<"i "<<lft[i]<<"# ";
        }
       // cout<<"\n";
        sum =0;
        for(int i=n-1;i>=0;i--)
        {
            sum += nums[i];
            if(i<n-1)
            {
                rgt[i] = sum - nums[i];
            }
          //  cout<<i<<"i "<<rgt[i]<<"# ";
        }
     //   cout<<"\n";
     for(int i=0;i<n;i++)
     {
        if(lft[i]==rgt[i])return i;
     } 

     
    return -1;
    }
};