class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        found = False
        ans = 0
        if n == 1:
            return 0
        
        for i in range(n):
            if i == 0 and nums[i] > nums[i+1]:
                ans  = i
                found = True
            elif i == n-1 and nums[i] > nums[i-1]:
                ans = i
                found = True
            elif nums[i-1] < nums[i] > nums[i+1]:
                ans = i
                found = True
            
            if found:
                return ans
