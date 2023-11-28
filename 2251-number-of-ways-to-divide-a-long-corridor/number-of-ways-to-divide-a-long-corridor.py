class Solution:
    def numberOfWays(self, cor: str) -> int:
        if(cor.count('S')==1):
            return 0
        if(cor.count('S')==2):
            return 1

        l=[]
        ct=0
        res=0
        i=0
        while i<len(cor):
            if(i==len(cor)-1 and ct==0 and cor[i]=='S'):
                return 0

            if(i==len(cor)-1 and ct==1 and cor[i]!='S'):
                return 0

            if(ct==2):
                res=0
                while(i<len(cor) and cor[i]!="S"):
                    res+=1
                    i+=1
                if(i!=len(cor)): l.append(res)
                ct=0
                continue
            if(i<len(cor) and cor[i]=="S"):
                ct+=1
            i+=1
        
        if(len(l)==0): return 0
        print(l)
        ans=1
        for i in l:
            ans*=(i+1)

        return ans%(1000000007)