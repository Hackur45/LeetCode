class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        filtered = [nums[0]]
        for num in nums[1:]:
            if num != filtered[-1]:
                filtered.append(num)

        ans = 0
        for i in range(1, len(filtered)-1):
            if filtered[i-1] < filtered[i] > filtered[i+1] or filtered[i-1] > filtered[i] < filtered[i+1]:
                ans += 1
        return ans
