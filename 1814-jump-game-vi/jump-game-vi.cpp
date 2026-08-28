class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        //sliding window maximum cses
        deque<int>q;
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        q.push_back(0);
        for(int i=1;i<n;i++){
            while(!q.empty() && q.front()<i-k){
                q.pop_front();
            }
            dp[i] = nums[i] + dp[q.front()];
            while(!q.empty() && dp[q.back()]<=dp[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        return dp[n-1];
    }
};