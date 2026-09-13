class Solution {
public:
    int maxProduct(string s) {
        int n=s.size();
        int N=1<<n;

        vector<int> dp(N,0);

        for(int mask=1;mask<N;mask++){
            int l=-1,r=-1;

            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    if(l==-1) l=i;
                    r=i;
                }
            }

            if(l==r){
                dp[mask]=1;
            }
            else if(s[l]==s[r]){
                int inside=mask^(1<<l)^(1<<r);
                dp[mask]=dp[inside]+2;
            }
            else{
                dp[mask]=max(
                    dp[mask^(1<<l)],
                    dp[mask^(1<<r)]
                );
            }
        }

        int ans=0;

        for(int mask=0;mask<N;mask++){
            int other=(N-1)^mask;
            ans=max(ans,dp[mask]*dp[other]);
        }

        return ans;
    }
};