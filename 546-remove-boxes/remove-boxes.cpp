class Solution {
public:
    int mcm(int i,int j,int extra,vector<int>&boxes,vector<vector<vector<int>>>&dp){
        //base case
        if(i>j){
            return 0;
        }
        if(dp[i][j][extra]!=-1) return dp[i][j][extra];
        int cnt=0;
        int k = i;
        while(k<=j&&boxes[i]==boxes[k]){
            cnt++;
            k++;
        }
        int op1 = INT_MIN;
        //remove current group now
        op1=max(op1,(cnt+extra)*(cnt+extra)+mcm(i+cnt,j,0,boxes,dp));
        for(int m=i+cnt;m<=j;m++){
            if(boxes[m]==boxes[i]){
                op1=max(op1,mcm(i+cnt,m-1,0,boxes,dp)+mcm(m,j,cnt+extra,boxes,dp));
            }
        }
        return dp[i][j][extra]=op1;
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>>dp(101,vector<vector<int>>(101,vector<int>(101,-1)));
        // max point to cover i to j boxes having extra count of box[i]
        
        return mcm(0,n-1,0,boxes,dp);
    }
};