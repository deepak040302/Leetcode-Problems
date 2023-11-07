class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        l=sorted([dist[i]/speed[i] for i in range(len(dist))])
        for i in range(len(l)):
            if l[i] <= i: return i
        return len(dist)
