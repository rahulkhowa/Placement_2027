class Solution {
public:
    long long perm(int n,int r){
        long long result=1;
        for(int i=0;i<r;i++){
            result*=(n-i);
        }
        return result;
    }
    int countNumbersWithUniqueDigits(int n){
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]+=dp[i-1]+9*perm(9,i-1);
        }
        return dp[n];
    }
};