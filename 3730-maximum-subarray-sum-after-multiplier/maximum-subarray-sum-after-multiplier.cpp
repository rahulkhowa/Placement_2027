class Solution {
public:
    #define ll long long
    long long maxSubarraySum(vector<int>& nums, int k) {
        ll ans = -1e16;
        auto solve = [&](bool flg){
           ll dp0 = 0;
           ll dp1 = -1e16;
           ll dp2 = -1e16;
           for(int x:nums){
              ll mod = flg ? 1LL*x*k : x/k;
              ll ndp0 = max(0LL,dp0)+x;
              ll ndp1 = max({0LL,dp0,dp1})+mod;
              ll ndp2 = max(dp1,dp2)+x;
              ans=max({ans,ndp1,ndp2});
              dp0 = ndp0;
              dp1 = ndp1;
              dp2 = ndp2;
           }
        };
        solve(0);
        solve(1);
        return ans;
    }
};