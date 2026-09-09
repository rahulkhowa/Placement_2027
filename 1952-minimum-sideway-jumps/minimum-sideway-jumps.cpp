class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int>dp = {1,0,1};
        for(int i=1;i<n;i++){
            int blocked = obstacles[i]-1;
            if(blocked>=0){
                dp[blocked]=INT_MAX;
            }
            int mn = *min_element(dp.begin(),dp.end());
            for(int l=0;l<3;l++){
                if(l!=blocked){
                   dp[l]=min(dp[l],mn+1);
                }
                // else{
                //     dp[l]=min(dp[l],mn);
                // }
            }
        }
        return *min_element(dp.begin(),dp.end());
    }
};