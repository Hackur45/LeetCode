class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (auto& a : nums) {
            v.push_back(to_string(a));
        }

        sort(v.begin(), v.end(), [](string a, string b) {
            return a + b > b + a;
        });

        if (v[0] == "0") return "0"; 

        string ans = "";
        for (auto& a : v) {
            ans += a;
        }

        return ans;
    }
};
