class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        if(n==0)return t[0];
        
        // Brute Force TC:O(n*n) SC:O(1)
        // Improved Sort TC:O(n*logn) SC:O(1)
        // Umap - HashTable TC:O(n) SC:O(n)
        // xor - TC:O(n) SC:O(1)
        
        int sum1 = 0;
		int sum2 = t[s.size()]; // Due to our loop will not reach it.
		for(int i = 0; i < s.length(); i++){
			sum1 += s[i];
			sum2 += t[i];
            // This adds Ascii values
           // cout<<i<<" "<<sum1<<" "<<sum2<<"\n";
		}
        // This returns desired char
		return char(abs(sum2 - sum1));
        
    }
};