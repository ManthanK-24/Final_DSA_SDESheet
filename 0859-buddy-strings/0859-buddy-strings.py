class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        cnt = 0
        n1 = len(s)
        n2 = len(goal)
        if(n1!=n2):
            return 0
        x=-1
        y=-1
        for i in range(0,n1):
            #print(s[i]+' '+goal[i])
            if(s[i]!=goal[i]):
                cnt=cnt+1
                if(x==-1):
                    x=i
                elif(y==-1):
                    y=i
        #print(cnt)
        
        
        if(cnt!=0 and cnt!=2):
            return 0
        if(cnt==2):
            return(s[x]==goal[y] and s[y]==goal[x])
            #return 1
        mp = dict()
        cnt=0
        for i in range(0,n1):
            mp[s[i]] = mp.get(s[i],0)+1
            #print(s[i],mp[s[i]])
            if(mp[s[i]]>1):
                cnt=1
                break
        return cnt