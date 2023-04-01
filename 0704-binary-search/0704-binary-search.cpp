class Solution {
public:
    int search(vector<int>& ar, int x) {
      
        int n = ar.size();
        int l =0, r =n-1;
        while(l<=r)
        {
            int m = l + (r-l)/2;
            if(ar[m]>x){
                r = m-1;
            }
            else if(ar[m]<x){
                l = m+1;
            }
            else{
                return m;
            }
        }
        return -1;
    }
};