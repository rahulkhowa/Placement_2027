class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // consider reverse path also as a forward path
        // then problem becomes simultaneous two robots
        // r1+c1 == r2+c2 (at each step)

        int n = grid.size();

        // dp[r1][c1][c2] =
        // max cherries collected by two robots
        // P1 = (r1,c1)
        // P2 = (r2,c2)
        // r2 = r1+c1-c2

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n, vector<int>(n, INT_MIN))
        );

        dp[0][0][0] = grid[0][0];

        for(int r1 = 0; r1 < n; r1++) {
            for(int c1 = 0; c1 < n; c1++) {

                for(int c2 = 0; c2 < n; c2++) {

                    int r2 = r1 + c1 - c2;

                    if(r2 < 0 || r2 >= n)
                        continue;

                    if(grid[r1][c1] == -1 || grid[r2][c2] == -1)
                        continue;

                    int one = INT_MIN;
                    int two = INT_MIN;
                    int three = INT_MIN;
                    int four = INT_MIN;

                    // P1 came from up
                    if(r1 - 1 >= 0) {
                        one = dp[r1-1][c1][c2];

                        // P1 came from up, P2 came from left
                        if(c2 - 1 >= 0) {
                            three = dp[r1-1][c1][c2-1];
                        }
                    }

                    // P1 came from left
                    if(c1 - 1 >= 0) {
                        two = dp[r1][c1-1][c2];

                        // P1 came from left, P2 came from left
                        if(c2 - 1 >= 0) {
                            four = dp[r1][c1-1][c2-1];
                        }
                    }

                    int f = max({one, two, three, four});

                    if(f == INT_MIN)
                        continue;

                    int cherries = grid[r1][c1];

                    if(r1 != r2 || c1 != c2)
                        cherries += grid[r2][c2];

                    dp[r1][c1][c2] = f + cherries;
                }
            }
        }

        return max(0, dp[n-1][n-1][n-1]);
    }
};