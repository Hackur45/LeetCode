class Solution {
public:
    void boostCode(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int tupleSameProduct(vector<int>& nums) {
        boostCode();
        unordered_map<int,int> mp;

        int n = nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int product = nums[i] * nums[j];
                mp[product]++;
            }
        }

        int ans = 0;
        for(auto &[a,b] : mp){
            if(b > 1){
                 ans += (b * (b - 1)) / 2 * 8;
            }
        }

        return ans;
    }
};