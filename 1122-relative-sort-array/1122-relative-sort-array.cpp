class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        
        int i = 0;
        
        for(int j=0;j<arr2.size();j++)
        {
            for(int k=0;k<arr1.size();k++)
            {
                if(arr1[k]==arr2[j])
                {
                    swap(arr1[k],arr1[i++]);
                }
            }
        }
        sort(arr1.begin()+i,arr1.end());
        return arr1;
    }
};