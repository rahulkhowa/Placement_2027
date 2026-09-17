class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        dp[0][0] = grid[0][0];

        for(int k = 1; k <= 2*n-2; k++) {

            vector<vector<int>> ndp(n, vector<int>(n, INT_MIN));

            for(int r1 = 0; r1 < n; r1++) {
                int c1 = k-r1;

                if(c1 < 0 || c1 >= n || grid[r1][c1] == -1)
                    continue;

                for(int r2 = 0; r2 < n; r2++) {
                    int c2 = k-r2;

                    if(c2 < 0 || c2 >= n || grid[r2][c2] == -1)
                        continue;

                    int cherries = grid[r1][c1];

                    if(r1 != r2)
                        cherries += grid[r2][c2];

                    for(int dr1 : {0,1}) {
                        for(int dr2 : {0,1}) {

                            int pr1 = r1-dr1;
                            int pr2 = r2-dr2;

                            if(pr1 < 0 || pr2 < 0)
                                continue;

                            if(dp[pr1][pr2] == INT_MIN)
                                continue;

                            ndp[r1][r2] = max(
                                ndp[r1][r2],
                                dp[pr1][pr2] + cherries
                            );
                        }
                    }
                }
            }

            dp = ndp;
        }

        return max(0, dp[n-1][n-1]);
    }
};