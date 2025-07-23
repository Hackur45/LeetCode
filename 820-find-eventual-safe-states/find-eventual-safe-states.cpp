class Solution {
private:
    bool dfs(vector<vector<int>> &graph,vector<int> &vis,int node){
        if(vis[node] == 1) return false;

        if(vis[node] == 2) return true;

        vis[node]=1;
        for(int a : graph[node]){
            if(!dfs(graph,vis,a)){
                return false;
            }
        }

        vis[node] = 2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,vis,i);
            }
        }

        for(int i=0;i<n;i++){
            if(vis[i] == 2){
                ans.push_back(i);
            }
        }

        return ans;
    }
};