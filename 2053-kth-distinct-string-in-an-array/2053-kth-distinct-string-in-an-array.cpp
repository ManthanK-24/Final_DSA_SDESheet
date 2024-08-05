class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        unordered_map<string,int> freq;
        
        int cnt = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            freq[arr[i]]++; 
        }
        
        for(int i=0;i<arr.size();i++)
        {
            //cout<<x<<"$ "<<y<<"#\n";
            if(freq[arr[i]]==1)
            {
                cnt++;
            if(cnt==k)return arr[i];
            }
        }
       // cout<<"%\n";
        return "";
    }
};