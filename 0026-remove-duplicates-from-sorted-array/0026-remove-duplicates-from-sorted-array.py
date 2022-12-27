class Solution:
    def removeDuplicates(self, ar: List[int]) -> int:
        res = 1
        n = len(ar)
        for i in range(1,n):
            if(ar[i]!=ar[i-1]):
                ar[res] = ar[i]
                res += 1
        return res
        
        