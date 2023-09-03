class Solution:
    def maxSum(self, nums: List[int], m: int, k: int) -> int:
        i=0
        j=0
        d={}
        ans=0
        s=0
        while j<len(nums):
            s+=nums[j]
            if nums[j] in d:
                d[nums[j]]+=1
            else:
                d[nums[j]]=1
            
            if(j-i+1 < k):
                j+=1
            else:
                if(len(d)>=m): 
                    ans=max(ans,s)
                    
                
                d[nums[i]]-=1
                if d[nums[i]]==0:
                    del d[nums[i]]
                s-=nums[i]
                i+=1
                j+=1
        return ans
                    
                
                
                
            
            