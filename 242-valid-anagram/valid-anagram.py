class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        from collections import Counter
        
        d1=Counter(s)
        d2=Counter(t)
        
        
        if(d1==d2):
            return True
        else:
            return False
        