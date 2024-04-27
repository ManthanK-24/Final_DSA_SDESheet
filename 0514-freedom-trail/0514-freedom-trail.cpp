class Solution {
public:
    int findRotateSteps(string ring, string key) {
        
        int rsz = ring.size(), ksz = key.size();
        vector<vector<int>> mem(rsz,vector<int>(ksz,0));
        
        vector<int> pos[26];
        
        for(int i=0;i<rsz;i++)
        {
               pos[ring[i]-'a'].push_back(i);
        }
        return findSteps(0,0,ring, key, pos,mem);
        
    }
    int findSteps(int p1,int p2, string& ring, string& key, vector<int> pos[26],       vector<vector<int>>& mem)
    {
        if(p2==key.size())return 0;
        
        if(mem[p1][p2])return mem[p1][p2];
        int mns = INT_MAX; 
        int rsz = size(ring);
        for(int nxt:pos[key[p2]-'a'])
        {
            int df = abs(p1-nxt);
            mns = min(mns,min(df,rsz-df) + findSteps(nxt,p2+1,
                                                 ring, key,pos,mem));
        }
        return mem[p1][p2] = mns+1;
    }
};