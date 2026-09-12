class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        vector<long long> dp(n);
        dp[0] = 1;

        int k = primes.size();

        vector<int> pr(k);

        // initialize once
        for(int i = 1; i < n; i++){

            long long nxt = LLONG_MAX;

            // find minimum candidate
            for(int j = 0; j < k; j++){
                nxt = min(nxt, dp[pr[j]] * 1LL * primes[j]);
            }

            dp[i] = nxt;

            // increment every pointer producing nxt
            for(int j = 0; j < k; j++){
                if(dp[pr[j]] * 1LL * primes[j] == nxt){
                    pr[j]++;
                }
            }
        }

        return dp[n-1];
    }
};