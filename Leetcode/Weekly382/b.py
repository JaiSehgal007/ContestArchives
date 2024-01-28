class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        c={}
        for e in nums: 
            c[e]=c.get(e,0)+1
        
        res=1
        for k,v in sorted(c.items()):
            if v>=2:
                tmp,cur=2,k
                c[k]-=2
                while cur*cur in c:
                    if c[cur*cur]>=2:
                        tmp+=2
                        c[cur*cur]-=2
                    elif c[cur*cur]==1:
                        tmp+=1
                        c[cur*cur]-=1
                        break
                    else:
                        break
                    cur=cur*cur
                    
                res=max(res,tmp if tmp%2==1 else tmp-1)
                
        return res