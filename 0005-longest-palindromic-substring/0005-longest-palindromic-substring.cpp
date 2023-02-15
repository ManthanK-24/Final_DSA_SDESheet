class Solution {
public:
    int lo, mxlen;
    string longestPalindrome(string s) {
        
        // Brute TC:O(n^3) two loops for substring & reverse for palindrome check
        if(s.size()<2)return s;
        for(int i=0;i<s.size()-1;i++){
            extendPalindrome(s,i,i);  // odd
            extendPalindrome(s,i,i+1); // even
        }
        return s.substr(lo,mxlen);
    }
    void extendPalindrome(string s, int i,int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        if(mxlen<j-i-1){
            lo = i+1;
            mxlen = j-i-1;
        }
    }
};