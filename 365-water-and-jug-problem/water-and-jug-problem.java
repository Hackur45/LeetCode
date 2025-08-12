class Solution {
    public static int[][] vis; 

    public static boolean dfs(int a,int b,int xm,int ym,int target){
        if(a + b == target) return true;
        if(vis[a][b] == 1) return false;

        vis[a][b] = 1;

        if(dfs(a,ym,xm,ym,target)) return true;

        if(dfs(xm,b,xm,ym,target)) return true;

        if(dfs(0,b,xm,ym,target)) return true;

        if(dfs(a,0,xm,ym,target)) return true;

        int p = Math.min(a,ym-b);
        if(dfs(a-p,b+p,xm,ym,target)) return true;
        p = Math.min(b,xm-a);
        if(dfs(a+p,b-p,xm,ym,target)) return true;

        return false;
    }
    public boolean canMeasureWater(int x, int y, int target) {
        vis = new int[x + 1][y + 1];
        return dfs(0,0,x,y,target);
    }
}