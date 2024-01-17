class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> freq, ocr;
        
        for(int i=0;i<arr.size();i++)
        {
            freq[arr[i]]++;
        }
        for(auto [x,y]:freq)
        {
            ocr[y]++;
        }
        for(auto [x,y]:ocr)
        {
            if(y>1)return 0;
        }
        
        return 1;
    }
};