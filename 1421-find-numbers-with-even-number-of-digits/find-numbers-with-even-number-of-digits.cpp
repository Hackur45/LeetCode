class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;

        for(auto &a : nums){
            string temp = to_string(a);
            if(temp.size() % 2 == 0){
                ans++;
            }
        }

        return ans;
    }
};