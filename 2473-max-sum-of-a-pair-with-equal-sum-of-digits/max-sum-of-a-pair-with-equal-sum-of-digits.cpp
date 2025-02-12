class Solution {
public:
    int digitsum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        map<int, vector<int>> mp;

        for (auto& a : nums) {
            mp[digitsum(a)].push_back(a);
        }
        int ans = 0;
        for (auto& [key, val] : mp) {
            if (val.size() < 2) continue; 
            sort(val.begin(), val.end(),greater<int>());           
            ans = max(ans, val[0] + val[1]); 
        }

        return ans == 0 ? -1 : ans;
    }
};