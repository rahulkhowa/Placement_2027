class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0][0] == 1) {
            return 0;
        }

        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols,0));
        dp[0][0] = 1;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (obstacleGrid[r][c] == 1) {
                    dp[r][c] = 0;
                } else {
                    int one = 0,two=0;
                    if(r>0){
                        one=dp[r-1][c];
                    }
                    if(c>0){
                        two=dp[r][c-1];
                    }
                    dp[r][c]+=one+two;
                }
            }
        }

        return dp[rows-1][cols - 1];        
    }
};