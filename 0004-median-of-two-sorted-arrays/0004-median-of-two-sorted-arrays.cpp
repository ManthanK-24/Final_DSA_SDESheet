class Solution {
public:
    double findMedianSortedArrays(vector<int>& ar1, vector<int>& ar2) {
        
        int n1 = ar1.size(), n2 = ar2.size();
        if(n1<n2)return findMedianSortedArrays(ar2,ar1);
        int lo = 0, hi = n2*2;
        while(lo<=hi)
        {
            int mid2 = (lo+hi)/2;
            int mid1 = n1+n2-mid2;
            
            double l1 = (mid1==0)? INT_MIN:ar1[(mid1-1)/2];
            double l2 = (mid2==0)? INT_MIN:ar2[(mid2-1)/2];
            double r1 = (mid1==2*n1)? INT_MAX:ar1[mid1/2];
            double r2 = (mid2==2*n2)? INT_MAX:ar2[mid2/2];
            
            if(l1>r2) lo = mid2+1;
            else if(l2>r1) hi = mid2-1;
            else return (max(l1,l2)+min(r1,r2))/2;
        }
        return -1;
    }
};