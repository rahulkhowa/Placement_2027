class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>dp(m,INT_MAX);// min cost 
        for(int j=0;j<m;j++){
            dp[j]=grid[0][j];
        }
        for(int i=1;i<n;i++){
            vector<int>ndp(m,INT_MAX);
            for(int j=0;j<m;j++){
                int val = grid[i][j];
                int mn = INT_MAX;
                for(int j1=0;j1<m;j1++){
                   mn=min(mn,dp[j1]+moveCost[grid[i-1][j1]][j]);
                }
                ndp[j]=mn+val;
            }
            dp=ndp;
        }
        return *min_element(dp.begin(),dp.end());
    }
};