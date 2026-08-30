class Solution {
public:
    bool can(int wait,vector<vector<int>>& grid,vector<vector<int>>&ft){
        int n = grid.size();
        int m = grid[0].size();
        if(wait>=ft[0][0])
        return false;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>pt(n,vector<int>(m,-1));
        vector<vector<int>>dis = {{-1,0},{1,0},{0,-1},{0,1}};
        // vis[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});
        pt[0][0]=wait;
        while(!q.empty()){
            auto [i,j]=q.front();q.pop();
            int t = pt[i][j]+1;
            for(int k=0;k<4;k++){
                int ni = i+dis[k][0];
                int nj = j+dis[k][1];
                if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]!=2 && pt[ni][nj]==-1){
                    if(ni==n-1 && nj==m-1){
                        if(t<=ft[ni][nj]){pt[ni][nj]=t;
                        // vis[ni][nj]=1;
                        q.push({ni,nj});}
                    }
                    else{
                        if(t<ft[ni][nj]){pt[ni][nj]=t;
                        // vis[ni][nj]=1;
                        q.push({ni,nj});}
                    }
                }
            }
        }
        return pt[n-1][m-1]!=-1;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>ft(n,vector<int>(m,1e9));
        vector<vector<int>>pt(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ft[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dis = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int ni = i+dis[k][0];
                int nj = j+dis[k][1];
                if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]!=2){
                    if(ft[ni][nj]==1e9){
                        ft[ni][nj]=ft[i][j]+1;
                        q.push({ni,nj});
                    }
                }
            }
        }
        if(!can(0,grid,ft))
            return -1;
        if(ft[n-1][m-1]==1e9) return 1e9;
        int l=0,h=n*m;
        int ans=-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(can(mid,grid,ft)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};