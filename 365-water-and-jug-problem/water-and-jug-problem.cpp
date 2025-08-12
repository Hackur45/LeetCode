class Solution {
public:
    bool dfs(int a,int b,int xm,int ym,int target,vector<vector<int>> &vis){
        if(a+b == target) return true;
        if(vis[a][b]) return false;
        vis[a][b] = 1;

        //b ka waise ka waisa, x ko pura bhar do
        if(dfs(xm,b,xm,ym,target,vis)) return true;

        //a ka waise ka waisa, y ko pura bhar do
        if(dfs(a,ym,xm,ym,target,vis)) return true;

        //a ko khali b waise ka waisa
        if(dfs(0,b,xm,ym,target,vis)) return true;

        //b ko khali a ko waise ka waisa
        if(dfs(a,0,xm,ym,target,vis)) return true;


        //a me se nikal ke b me dal
        int pour = min(a,ym-b);
        if(dfs(a-pour,b+pour,xm,ym,target,vis)) return true;

        //b mese nikal ke a me dal
        pour = min(b,xm-a);
        if(dfs(a+pour,b-pour,xm,ym,target,vis)) return true;

        // saw all combination didn't found any valid one
        return false;
    }
    bool canMeasureWater(int x, int y, int target) {
        vector<vector<int>> vis(x+1,vector<int>(y+1,0));
        return dfs(0,0,x,y,target,vis);
    }
};

/*

mathematical approach

agar dono ka i.e gcd(x,y) fully divide kr skta hai apne target ko toh ans possible hai

edge case: 
    agar x+y > target; so anyhow not possible 

    if x + y > target:
        return False
    return target%__gcd(x,y) == 0
*/