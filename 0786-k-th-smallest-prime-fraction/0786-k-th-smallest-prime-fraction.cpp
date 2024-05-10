class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        vector<int> ans;
        
        vector<pair<double,vector<int>>> vp;
        
        for(int i=0;i<size(arr);i++)
        {
            for(int j=i+1;j<size(arr);j++)
            {
                double val = arr[i]/(1.0*arr[j]);
                vp.push_back({val,{arr[i],arr[j]}});
            }
        }
        sort(vp.begin(),vp.end());
        
        ans = {vp[k-1].second[0],vp[k-1].second[1]};
        return ans;
        
    }
};