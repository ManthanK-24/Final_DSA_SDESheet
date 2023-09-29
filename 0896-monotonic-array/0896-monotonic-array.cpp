class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        int n = nums.size();
        if(n<=2)return 1;
        
        bool isIncreasing = 1;
        int i = 0;
        while(i<n)
        {
            while(i+1<n && nums[i]==nums[i+1])
            {
                i++;
            }
            if(i<n)
            {
                if(i>=1 && nums[i] < nums[i-1]) // decreasing
                {
                    isIncreasing = 0;
                    break;
                }
                else if(i<n-1)
                {
                    if(nums[i] > nums[i+1])
                    {
                        isIncreasing  = 0;
                        break;
                    }
                    else
                        break;
                }
            }
            i++;
        }
     //   cout<<i<<" "<<isIncreasing<<"#\n";
        
        if(isIncreasing){
            for(int j=i;j<n;j++){
                if(j+1<n && nums[j] > nums[j+1])
                {
                    return 0;
                }
             //   cout<<j<<"x ";
            }
        }
        else{
            for(int j=i;j<n;j++){
                if(j+1<n && nums[j] < nums[j+1])
                {
                    return 0;
                }
               //  cout<<j<<"x ";
            }
        }
   //     cout<<"$\n";
        return 1;
    }
};