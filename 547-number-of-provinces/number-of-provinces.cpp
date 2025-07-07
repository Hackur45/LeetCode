class Solution {

private:
    void dfs(vector<vector<int>> &graph , vector<int> &visited,int x){
        visited[x] = 1;

        int n = graph.size();

        for(int i=0;i<n;i++){
            if(graph[x][i] == 1 && !visited[i]){
                dfs(graph,visited,i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);

        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,visited,i);
                ans++;
            }
        }
        return ans;
    }
};