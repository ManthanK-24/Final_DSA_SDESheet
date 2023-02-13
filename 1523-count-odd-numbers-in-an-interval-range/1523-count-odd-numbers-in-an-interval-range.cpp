class Solution {
public:
    int countOdds(int l, int r) {
        
        int ans=0;
        if(l==r){
            ans = r%2;
        }
        else if(l%2 and r%2){
            ans = (r-l-1)/2;
            ans += 2;
        }
        else if(l%2==0 and r%2==0){
            ans = (r-l)/2;
        }
        else{
            ans = (r-l)/2;
            ans++;
        }
       
        return ans;
    }
};