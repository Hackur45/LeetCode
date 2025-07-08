class Solution {
  public:
  
  void dfs(vector<vector<int>> &image, set<pair<int,int>> &v, int sr, int sc, int pr, int pc){
    int n = image.size();
    int m = image[0].size();
      
    if(sr<0 || sc<0 || sr>=n || sc>=m) return;
      
      if(v.count({sr,sc})) return;
    if(image[sr][sc] == image[pr][pc])
        {
            v.insert({sr,sc});
            dfs(image, v, sr + 1, sc, sr, sc);
            dfs(image, v, sr - 1, sc, sr, sc);
            dfs(image, v, sr, sc + 1, sr, sc);  
            dfs(image, v, sr, sc - 1, sr, sc);
        }
  }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        
        set<pair<int,int>> v;
        dfs(image,v,sr,sc,sr,sc);
        
        for(pair<int,int> a : v){
            image[a.first][a.second] = newColor;
        }
        
        return image;
    }
};