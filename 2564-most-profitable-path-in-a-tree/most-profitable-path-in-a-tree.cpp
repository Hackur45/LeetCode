class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& e, int b, vector<int>& a) {
        int n = a.size();
        vector<vector<int>> adj(n);
        
        for (auto& x : e) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> d(n, -1); 
        int t = 0, ans = INT_MIN;
        
        function<bool(int, int)> findB = [&](int node, int par) {
            if (node == b) {
                d[node] = 0;
                return true;
            }
            for (int next : adj[node]) {
                if (next == par) continue;
                if (findB(next, node)) {
                    d[node] = d[next] + 1;
                    return true;
                }
            }
            return false;
        };
        
        findB(0, -1);
        
        function<void(int, int, int)> dfs = [&](int node, int par, int gain) {
            bool isLeaf = true;
            if (d[node] == -1 || t < d[node]) 
                gain += a[node];
            else if (t == d[node]) 
                gain += a[node] / 2;
            
            t++;
            for (int next : adj[node]) {
                if (next == par) continue;
                isLeaf = false;
                dfs(next, node, gain);
            }
            t--;
            if (isLeaf) ans = max(ans, gain);
        };
        
        dfs(0, -1, 0);
        return ans;
    }
};
