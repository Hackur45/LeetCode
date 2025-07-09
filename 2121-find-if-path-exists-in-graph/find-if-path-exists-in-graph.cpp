class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> graph;
        if(edges.size() == 0){
            return true;
        } 
        for(auto &edge : edges){
            //construct bidirectional graph
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n,0);
        queue<int> q;
        q.push(source);

        while(!q.empty()){
            int a = q.front();q.pop();
            if(a == destination) return true;
            for(auto &gp : graph[a]){
                if(!visited[gp]){
                    q.push(gp);
                    visited[gp] = 1;
                }
            }
        }

        return false;
    }
};