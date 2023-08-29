class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n=[]
        y=[-1]*len(customers)
        
        ct=0
        for i in customers:
            n.append(ct)
            if i=='N': ct+=1
        ct=0
        for i in range(len(customers)-1,-1,-1):
            # print(i)
            y[i]=ct
            if customers[i]=='Y': ct+=1

        ans=[]
        for i in range(len(customers)):
            ct=0
            if(customers[i]=='Y'): ct+=1
            ct+=(y[i]+n[i])
            ans.append(ct)
            
        lp=0
        
        for i in customers:
            if(i=='N'): lp+=1
                
        mini=0
        mini_v=ans[0]
        for i in range(len(ans)):
            if(mini_v>ans[i]):
                mini=i
                mini_v=ans[i]
        
        if(lp<mini_v):
            return len(customers)
        return mini