class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){
                    dp[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dis = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto [i,j]=q.front();q.pop();
            for(int k=0;k<4;k++){
                int ni = i+dis[k][0];
                int nj = j+dis[k][1];
                if(ni>=0&&nj>=0&&ni<n&&nj<m&&dp[ni][nj]>dp[i][j]+1){
                    dp[ni][nj]=dp[i][j]+1;
                    q.push({ni,nj});
                }
            }
        }
        return dp;
    }
};