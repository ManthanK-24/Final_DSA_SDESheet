class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0: return 0
        t0 = 0
        t1 = 1
        t2 = 1
        for i in range(n-2):
            tn = t0 + t1 + t2
            t0 = t1
            t1 = t2
            t2 = tn
        return t2
        