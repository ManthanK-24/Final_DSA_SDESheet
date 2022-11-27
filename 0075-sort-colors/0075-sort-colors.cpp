class Solution {
public:
    void sortColors(vector<int>& ar) {
        int low = 0, mid =0 , high = ar.size()-1;
        while(mid<= high)
        {
            if(ar[mid]==0)
            {
                swap(ar[mid],ar[low]);
                mid++;
                low++;
            }
            else if(ar[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(ar[mid],ar[high]);
                //mid++; 
                high--;
            }
        }
    }
};