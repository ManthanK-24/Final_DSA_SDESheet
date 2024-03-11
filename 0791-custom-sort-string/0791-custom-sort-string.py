class Solution:
    def customSortString(self, order: str, s: str) -> str:
        ans = ""
        mp = {}
        for e in s:
            if e in mp:
                mp[e] += 1
            else:
                mp[e] = 1
        for x in order:
            if x in mp:
                t = mp[x]
                while(t>0):
                    ans += x
                    t -= 1
        for k, v in mp.items():
            if k not in order:
                t = v
                while(t>0):
                    ans += k
                    t -= 1
            
        return ans