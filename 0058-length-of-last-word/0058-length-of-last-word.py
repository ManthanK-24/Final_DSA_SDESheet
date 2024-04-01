class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        lst = s.split()
        # print(lst)
        sz = len(lst)
        return len(lst[sz-1])