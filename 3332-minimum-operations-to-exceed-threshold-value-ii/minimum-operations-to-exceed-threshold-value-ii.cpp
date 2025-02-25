#define ll long long int 

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        ___b();
        priority_queue <ll, vector<ll>, greater<ll> > pq(nums.begin(), nums.end()); 
        int n = nums.size();
        int ans = 0;
        while(pq.top() < k){
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            pq.push(min(a,b) * 2 + max(a,b));
            ans++;
        }

        return ans;
    }

private: 
    void ___b(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
};