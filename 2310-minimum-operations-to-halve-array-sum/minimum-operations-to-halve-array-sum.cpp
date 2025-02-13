#define ll long long int
class Solution {
public:
    int halveArray(vector<int>& nums) {
        ___b(); 

        int n = nums.size();
        int ans = 0;
        ll ts = 0;

        for (auto &a : nums) ts += a;
        double cs = ts;  
        double target = ts / 2.0;


        priority_queue<double> pq;
        for (auto &a : nums) pq.push((double)a); 

        while (cs > target) {
            double a = pq.top();
            pq.pop();
            a /= 2.0; 
            cs -= a;
            pq.push(a);
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
