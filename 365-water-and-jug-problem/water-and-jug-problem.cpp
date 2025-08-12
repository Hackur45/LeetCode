class Solution {
public:
    bool dfs(int a,int b,int xm,int ym,int target,vector<vector<int>> &vis){
        if(a+b == target) return true;
        if(vis[a][b]) return false;
        vis[a][b] = 1;

        if(dfs(xm,b,xm,ym,target,vis)) return true;

        if(dfs(a,ym,xm,ym,target,vis)) return true;

        if(dfs(0,b,xm,ym,target,vis)) return true;

        if(dfs(a,0,xm,ym,target,vis)) return true;

        int pour = min(a,ym-b);
        if(dfs(a-pour,b+pour,xm,ym,target,vis)) return true;

        pour = min(b,xm-a);
        if(dfs(a+pour,b-pour,xm,ym,target,vis)) return true;

        return false;
    }
    bool canMeasureWater(int x, int y, int target) {
        vector<vector<int>> vis(x+1,vector<int>(y+1,0));
        return dfs(0,0,x,y,target,vis);
    }
};