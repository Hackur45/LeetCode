class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n,vector<int>());

        for(auto &a : prerequisites){
            graph[a[0]].push_back(a[1]);
        }


        queue<int> q;
        vector<int> ind(n, 0);

        for(int i=0;i<n;i++){
            for(int it: graph[i]){
                ind[it]++;
            }
        }


        for(int i=0;i<n;i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }

        // vector<int> ans;
        int ans = 0;
        while(!q.empty()){
            int a = q.front(); q.pop();
            ans++;
            for(int i : graph[a]){
                if(--ind[i] == 0){
                    q.push(i);
                }
            }
        }
        if(ans == n) return true;

        return false;
    }
};