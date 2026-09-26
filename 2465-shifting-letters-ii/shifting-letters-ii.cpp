class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>rank(n+1,0);
        for(auto s:shifts){
            int l = s[0];
            int r = s[1];
            int u = s[2];
            if(u==0) u = -1;
            rank[l]+=u;
            rank[r+1]-=u;
        }
        int pre=0;
        for(int i=0;i<n;i++){
            pre=(pre+rank[i])%26;
            if(pre<0){
                pre+=26;
            }
            s[i]='a'+(s[i]-'a'+pre)%26;
        }
        return s;
    }
};