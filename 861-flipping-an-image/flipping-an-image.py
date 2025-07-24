class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        
        for i,row in enumerate(image):
            image[i] = image[i][::-1]
        
        n = len(image)
        m = len(image[0])
        ans = [[0]*m for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if image[i][j] == 0:
                    ans[i][j] = 1
                else:
                    ans[i][j] = 0

        return ans 