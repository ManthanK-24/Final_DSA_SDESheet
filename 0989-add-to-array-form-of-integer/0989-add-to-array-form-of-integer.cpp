class Solution {
public:
    string twoStringSum(string s1,string s2){
        string ans;
        int carry = 0;
        int i = s1.size()-1, j = s2.size()-1;
        while(i>=0 && j>=0){
            int v = (s1[i]-'0')+(s2[j]-'0')+carry;
            if(v>=10){
                carry = v/10;
                v = v%10;
                ans += to_string(v);
            }
            else{
                ans += to_string(v);
                if(carry)carry=0;
            }
            i--;
            j--;
        }
        while(i>=0){
            int v = (s1[i]-'0') + carry;
            if(v>=10){
                carry = v/10;
                v = v%10;
                ans += to_string(v);
            }
            else{
                ans += to_string(v);
                if(carry)carry=0;
            }
            i--;
        }
        while(j>=0){
            int v = (s2[j]-'0') + carry;
            if(v>=10){
                carry = v/10;
                v = v%10;
                ans += to_string(v);
            }
            else{
                ans += to_string(v);
                if(carry)carry=0;
            }
            j--;
        }
        if(carry)ans += to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> addToArrayForm(vector<int>& num, int k) {
     
        vector<int> ans;
        string s1;
        for(int i=0;i<num.size();i++){
            s1 += to_string(num[i]);
        }
        
        string s2 = to_string(k);
        string s = twoStringSum(s1,s2);
        for(int i=0;i<s.size();i++)ans.push_back(s[i]-'0');
        return ans;
    }
};