class Solution {
public:
    int lps(string s) {
        int n = s.size();
        if(n==0) return 0;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j = i+len-1;
                if(s[i]==s[j]){
                    dp[i][j]=max(dp[i][j],dp[i+1][j-1]+2);
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
    bool isPal(string &s){
    int l=0,r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}
    int maxProduct(string s) {
        int n = s.size();
        int N = 1<<n;
        int ans=0;
        for(int mask=0;mask<N;mask++){
            string a = "",b="";
            for(int i=0;i<n;i++){
                if(!(mask&(1<<i))){
                    b+=s[i];
                }
                else{
                    a+=s[i];
                }
            }
            if(!isPal(a)) continue;
            int len1 = a.size();
            int len2 = lps(b);
            ans=max(ans,len1*len2);
        }
        return ans;
    }
};