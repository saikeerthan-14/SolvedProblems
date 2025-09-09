class Solution:
    def reverseWords(self, s: str) -> str:
        lst = s.strip().split()
        return " ".join(reversed(lst))
        
        
        
        