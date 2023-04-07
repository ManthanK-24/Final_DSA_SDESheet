class Solution {
public:
    vector<string> commonChars(vector<string>& a) {
        
        int hash[26] = {0};
        vector<string> o;
        for(char s : a[0])
            ++hash[s - 'a'];
        for(int i = 1; i < a.size(); ++i){
            int arr[26] = {0};
            for(char c : a[i]){
                ++arr[c - 'a'];
            }
            for(int i = 0; i < 26; ++i){
                if(arr[i] == 0) hash[i] = 0;
                else{
                    hash[i] = min(arr[i], hash[i]);
                }
            }
        }
        for(int i = 0; i < 26; ++i){
                while(hash[i] > 0){
                    string c = "";
                    c += (i + 'a');
                     //o.push_back(string(1,i+'a'));
                    o.push_back(c);
                    --hash[i];
                }
        }        
        return o;
    }
};