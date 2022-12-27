class Solution:
    def findMaxConsecutiveOnes(self, ar: List[int]) -> int:
        res = 0
        n = len(ar)
        if(max(ar)==1):
            res=1
        tmp = 0
        for i in range(1,n):
            if(ar[i]==ar[i-1] and ar[i]==1):
                if(tmp==0):
                    tmp += 2
                else:
                    tmp += 1
                if(i==n-1):
                    res = max(res,tmp)
            else:
                res = max(res,tmp)
                tmp = 0
        return res
        
        