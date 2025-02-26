class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int x = 0, y = 0, z = 0;
        
        for (int b : nums) {
            x = max(0, x + b);
            y = min(0, y + b);
            z = max(z, max(abs(x), abs(y)));
        }
        
        return z;
    }
};
