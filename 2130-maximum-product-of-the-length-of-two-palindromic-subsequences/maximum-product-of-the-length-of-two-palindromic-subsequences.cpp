class Solution {
public:
    int lps(string s) {
        string text1=s;
        string text2=s;reverse(text2.begin(),text2.end());
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        dp[0][0]=0;
        for(int i=0;i<text1.size();i++){
            for(int j=0;j<text2.size();j++){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
    bool isPal(string &s){
    int l=0,r=s.size()-1;
    while(l<r){
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