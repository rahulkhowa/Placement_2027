class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        int si, sj;

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]=='@'){
            si=i;
            sj=j;
        }
    }
}
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>='a' && grid[i][j]<='z'){
                    cnt++;
                }
            }
        }
        int N = 1<<cnt;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(N,-1)));
        dp[si][sj][0]=0;
        queue<tuple<int,int,int>>q;
        q.push({si,sj,0});
        vector<pair<int,int>>dis = {{0,-1},{0,1},{1,0},{-1,0}};
        while(!q.empty()){
            auto [i,j,mask]=q.front();q.pop();
            int d = dp[i][j][mask];
            if(mask==N-1) return d;
            for(auto [i1,j1]:dis){
                int ni = i+i1;
                int nj = j+j1;
                int nmask = mask;
                if(ni<0 || nj<0 || ni>=n || nj>=m) continue;
                if(grid[ni][nj]=='#') continue;
                if((grid[ni][nj]>='A' && grid[ni][nj]<='Z') && !(mask&(1<<(grid[ni][nj]-'A')))) continue;
                if(grid[ni][nj]>='a' && grid[ni][nj]<='z'){
                    int id = grid[ni][nj]-'a';
                    nmask|=(1<<id);
                }
                if(dp[ni][nj][nmask]==-1){
                    dp[ni][nj][nmask]=d+1;
                    q.push({ni,nj,nmask});
                }
            }
        }
        return -1;
    }
};