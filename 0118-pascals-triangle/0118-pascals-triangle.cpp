class Solution {
public:
    vector<vector<int>> generate(int nr) {
        vector<vector<int>> ans;
        for(int i=1;i<=nr;i++){
            vector<int> tmp;
            for(int j=1;j<=i;j++){
                if(j==1 || i==j){
                    tmp.push_back(1);
                }
                else{
                    int v = ans[ans.size()-1][j-2] + ans[ans.size()-1][j-1];
                    tmp.push_back(v); 
                }
            }
            ans.push_back(tmp);
        }
        return ans;
        
    }
};