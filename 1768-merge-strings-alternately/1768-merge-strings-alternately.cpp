class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans;
        int n1 = word1.size(), n2 = word2.size();
        int i=0,j=0, t = 1;
        while(i<n1 and j<n2){
            if(t){
                ans += word1[i];
                i++;
            }
            else{
                ans += word2[j];
                j++;
            }
            t = t^1;
        }
        while(i<n1)ans += word1[i],i++;
        while(j<n2)ans += word2[j],j++;
        return ans;
    }
};