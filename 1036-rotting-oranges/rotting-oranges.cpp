class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh=0;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int ans=0;
        vector<vector<int>>dis = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
           int sz = q.size();
           int flg=0;
           while(sz--){
              auto [i,j] = q.front();q.pop();
              for(int k=0;k<4;k++){
                int ni = i+dis[k][0];
                int nj = j+dis[k][1];
                if(ni>=0 && nj>=0 && ni<n && nj<m && !vis[ni][nj]){
                    if(grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        vis[ni][nj]=1;
                        q.push({ni,nj});
                        flg=1;
                        fresh--;
                    }
                }
              }
           }
           if(flg) ans++;
        }
        if(!fresh) return ans;
        return -1;
    }
};