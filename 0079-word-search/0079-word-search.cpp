class Solution {
public:
    
    bool poss(int r, int c,vector<vector<char>>& board, string word, int idx)
    {
        if(idx==word.size())return 1;
        
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size())
            return 0;
        
        if(board[r][c]!=word[idx])return 0;
        
        // cout<<r<<"r "<<c<<"c "<<idx<<"idx#\n";
       board[r][c]='*';
        
        bool ok = 0;
        ok = poss(r+1,c,board,word,idx+1) ||
             poss(r,c+1,board,word,idx+1) || 
             poss(r-1,c,board,word,idx+1) ||
             poss(r,c-1,board,word,idx+1);
        
        board[r][c]=word[idx];
        
        return ok;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
    
       for(int i=0;i<board.size();i++)
       {
           for(int j=0;j<board[0].size();j++)
           {
               
               if(poss(i,j,board,word,0))return 1;
               
           }
       }
        // cout<<"$\n";
        return 0;
    }
};