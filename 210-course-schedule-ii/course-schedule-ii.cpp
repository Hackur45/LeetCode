class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<vector<int>> graph(n,vector<int>());

        for(vector<int> &a : prerequisites){
            graph[a[0]].push_back(a[1]);
        }

        queue<int> q;
        vector<int> ind(n,0);
        for(int i=0;i<n;i++){
            for(auto &a : graph[i]){
                ind[a]++;
            }
        }

        for(int i=0;i<n;i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int a = q.front();q.pop();
            ans.push_back(a);
            for(int i : graph[a]){
                if(--ind[i] == 0){
                    q.push(i);
                }
            }
        }

        reverse(ans.begin(),ans.end());
        return ans.size() == n ? ans : vector<int>{}; 
    }
};