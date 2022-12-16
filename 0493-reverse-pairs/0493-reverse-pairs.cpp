class Solution {
public:
    int cnt;
    void merge(vector<int>& ar, int s,int m, int e)
    {
        int i = s, j= m+1;
        while(i<=m && j<= e)
        {
            if((long)ar[i]> (long) 2*ar[j] )
            {
                cnt += m-i+1;
                j++;
            }
            else
                i++;
            
        }
        sort(ar.begin()+s,ar.begin()+e+1);
    }
    void mergeSort(vector<int>& ar,int st, int end)
    {
        if(st>=end)return;
        int mid = (st+end)>>1;
        mergeSort(ar,st,mid);
        mergeSort(ar,mid+1,end);
        merge(ar,st,mid,end);
    }
    int reversePairs(vector<int>& nums) {
        if(!nums.size())return 0;
        cnt = 0;
        mergeSort(nums,0,nums.size()-1);
        return cnt;
    }
};