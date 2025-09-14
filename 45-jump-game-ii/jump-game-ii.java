class Solution {
    public int jump(int[] nums) {
        int n = nums.length;

        if(n == 1) return 0;
        int ld = 0, end = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            ld = Math.max(ld, nums[i] + i);

            if (i == end) {
                ans++;
                end = ld;
                if (ld >= n-1) {
                    return ans;
                }
            }
        }

        return ans;
    }
}