class Solution {
public:
    int mcm(int i,int j,int extra,string &s,vector<vector<int>>&dp){
        //base case
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int cnt=0;
        int k = i;
        while(k<=j&&s[i]==s[k]){
            cnt++;
            k++;
        }
        int op1 = INT_MAX;
        //remove current group now
        op1=min(op1,1+mcm(i+cnt,j,0,s,dp));
        for(int m=i+cnt;m<=j;m++){
            if(s[m]==s[i]){
                op1=min(op1,mcm(i+cnt,m-1,0,s,dp)+mcm(m,j,cnt+extra,s,dp));
            }
        }
        return dp[i][j]=op1;
    }
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return mcm(0,n-1,0,s,dp);
    }
};