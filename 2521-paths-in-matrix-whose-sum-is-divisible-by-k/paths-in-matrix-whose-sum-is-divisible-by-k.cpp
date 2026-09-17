class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 1e9+7;
        // dp[i][j][r] no of paths from 0,0 to i,j where sum of path modulo k is
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;
        for (int j = 1; j < m; j++) {
            for (int p = 0; p < k; p++) {
                int np = (p + grid[0][j]) % k;
                (dp[0][j][np] += dp[0][j - 1][p])%=MOD;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int p = 0; p < k; p++) {
                int np = (p + grid[i][0]) % k;
                (dp[i][0][np] += dp[i - 1][0][p])%=MOD;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                for (int p = 0; p < k; p++) {
                    int np = (p + grid[i][j]) % k;
                    (dp[i][j][np] += dp[i - 1][j][p])%=MOD;
                    (dp[i][j][np] +=dp[i][j-1][p])%=MOD;
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};