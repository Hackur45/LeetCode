class Solution {
private:
    void bfs(vector<vector<int>> &graph, vector<int> &v, int s){
        queue<int> q;
        q.push(s);
        v[s] = 1;
        int n = graph.size();

        while(!q.empty()){
            int a = q.front(); q.pop();

            for(int i=0;i<n;i++){
                if(graph[a][i] == 1 && !v[i]){
                    q.push(i);
                    v[i]=1;
                }
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
                bfs(isConnected,visited,i);
                ans++;
            }
        }

        return ans;
    }
};