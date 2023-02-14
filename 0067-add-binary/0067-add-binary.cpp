class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int i = a.size()-1, j= b.size()-1;
        while(i>=0 && j>=0){
            int v = (a[i]-'0')+(b[j]-'0')+carry;
            if(v==3){
                ans += '1';
            }
            else if(v==2){
                ans += '0';
                carry=1;
            }
            else{ // v==1 or v==0
                
                ans += to_string(v);
                if(carry)carry=0;
            }
            i--;
            j--;
        }
        while(i>=0 ){
            if(carry){
                int v = a[i]-'0'+1;
                if(v==2){
                    ans += '0';
                }
                else{
                ans += to_string(a[i]-'0'+1);
                carry=0;
                }
                
            }
            else{
                ans += to_string(a[i]-'0');
            }
            i--;
        }
        while(j>=0 ){
            if(carry){
                int v = b[j]-'0'+1;
                if(v==2){
                    ans += '0';
                }
                else{
                ans += to_string(b[j]-'0'+1);
                carry=0;
                }
                
            }
            else{
                ans += to_string(b[j]-'0');
            }
            j--;
        }
        if(carry)ans+= '1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};