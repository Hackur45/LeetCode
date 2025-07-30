class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // vector<int> vis(n,0);
        vector<vector<int>> graph(n,vector<int>());
        int ans = INT_MAX;
        //undirected graph
        for(auto &edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for(int i=0;i<n;i++){
            vector<int> dis(n,-1);
            queue<pair<int,int>> q;

            q.push({i,0});
            dis[i] = 0;

            while(!q.empty()){
                int v = q.front().first;
                int p = q.front().second;q.pop();

                for(auto &a : graph[v]){
                    if(a == p) continue;
                    else if(dis[a] == -1){
                        dis[a] = dis[v] + 1;
                        q.push({a,v});
                    }else{
                        ans = min(ans,dis[a] + dis[v] + 1);
                    }
                }
            }
        } 

        return ans == INT_MAX ? -1 : ans;
    }
};