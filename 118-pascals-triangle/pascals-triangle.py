import math
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans =[]

        for i in range(1,numRows+1):
            temp = []

            for j in range(i):
                temp.append(math.comb(i-1,j))
            
            ans.append(temp)
        
        return ans