class Solution {
public:
    void merge(vector<int>& ar, int l, int m ,int r)
    {
        int i = l, j = m+1, k =0;
        vector<int> tmp; //(r-l+1,0);
        while(i<=m && j<=r)
        {
            if(ar[i]>ar[j])
            {
                tmp.push_back(ar[j++]);
            }
            else
            {
                tmp.push_back(ar[i++]);
            }
        }
        while(i<=m)tmp.push_back(ar[i++]);
        while(j<=r)tmp.push_back(ar[j++]);
        for(int x=l;x<=r;x++)
            ar[x] = tmp[x-l];
        
    }
    void ms(vector<int>& ar,int l, int r)
    {
        if(l>=r)return;
        int m = l + (r-l)/2;
        ms(ar,l,m);
        ms(ar,m+1,r);
        merge(ar,l,m,r);
    }
    vector<int> sortArray(vector<int>& ar) {
        
        ms(ar,0,ar.size()-1);
        return ar;
    }
};