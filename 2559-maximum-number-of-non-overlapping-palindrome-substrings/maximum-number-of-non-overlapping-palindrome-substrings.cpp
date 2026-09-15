class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int>dp(n+1,0);//dp[i] = max number of substring of len>=k of a string = s[0....i]
        //we try every j <=i such that i-j+1>=k && ispalindrome(i,j-1) is true then dp[i] max(dp[i],dp[j]+1)
        vector<vector<int>>pal(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            pal[i][i]=1;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j = i+len-1;
                if(s[i]==s[j]){
                    if(len==2){
                        pal[i][j]=1;
                    }
                    else{
                        pal[i][j]=pal[i+1][j-1];
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            for(int j=0;j<=i-k;j++){
                if(pal[j][i-1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n];
    }
};