class Solution {
public:
    int bits(int x){
        return __builtin_popcount(x);
    }
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        //first make prerequisite dp
        vector<int>pre(n,0);
        for(auto e:relations){
            int u = e[0]-1;
            int v = e[1]-1;
            pre[u]|=(1<<v);
        }
        //state dp[mask] minimum sem required to complete the courses in mask
        //base case dp[0]=0 and return in end dp[1<<n-1]
        int N = 1<<n;
        vector<int>dp(N,n+1);
        dp[0]=0;
        for(int mask=0;mask<N;mask++){
           int can=0;
           for(int i=0;i<n;i++){
              if((pre[i]&mask)!=pre[i]) continue;
              if(mask&(1<<i)) continue;
              can|=(1<<i);
           }
           int cnt = bits(can);
           if(cnt<=k){
              int nmask = mask|can;
              dp[nmask]=min(dp[nmask],dp[mask]+1);
           }
           else{
              for(int sub=can;sub;sub=(sub-1)&can){
                 if(bits(sub)<=k){
                    int nmask = mask|sub;
                    dp[nmask]=min(dp[nmask],dp[mask]+1);
                 }
              }
           }
        }
        return dp[N-1];
    }
};