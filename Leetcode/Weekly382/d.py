# strategy is to itereate for all the bits
# now for each bit check the number of elements of the array that are contibuting to it
# if that are less that k that means this can become an unset bit
# or else we need to set this bit as well
class Solution:
    def minOrAfterOperations(self, nums: List[int], k: int) -> int:
        n,ans=len(nums),0

        for j in range(30,-1,-1):
            cnt=0
            cur=(1<<30)-1
            target=(ans|(1<<j)-1)

            for x in nums:
                cur&=x
                if((cur|target)==target):
                    cnt+=1
                    cur=(1<<30)-1
            
            if n-cnt > k:
                ans |=(1<<j)

        return ans
                