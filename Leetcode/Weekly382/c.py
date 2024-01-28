class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        if n>m: 
            n,m=m,n
        
        # choose any such that the sum is odd
        eL,eR=n//2,m//2
        oL,oR=n-eL,m-eR
        
        return int((eL*oR)+(eR*oL))
        
        