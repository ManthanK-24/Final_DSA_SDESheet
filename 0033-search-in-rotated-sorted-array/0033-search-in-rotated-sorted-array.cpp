class Solution {
public:
    int search(vector<int>& ar, int tar) {
        int n = ar.size();
        int lo = 0, hi = n-1;
        
        // find idx with smallest val BS
        while(lo<hi)
        {
            int mid = (lo+hi)/2;
            if(ar[mid]>ar[hi])lo=mid+1;
            else
                hi = mid;
        }
        int rot = lo;
        lo=0, hi=n-1;
        // actual BS with accounting rotation
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            int realmid = (mid + rot)%n;
            if(ar[realmid]==tar)return realmid;
            else if(ar[realmid]<tar)lo=mid+1;
            else
                hi = mid-1;
        }
         return -1;
    }
};