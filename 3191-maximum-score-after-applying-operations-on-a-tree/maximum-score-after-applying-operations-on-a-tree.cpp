class Solution {
public:
    vector<long long>dp,sub;
    long long dfs(int u,int par,vector<vector<int>>&adj,vector<int>& values){
         long long sum=0;
         sub[u]=values[u];
         for(int v:adj[u]){
            if(v==par) continue;
            sum+=dfs(v,u,adj,values);
            sub[u]+=sub[v];
            dp[u]=max(sub[u]-values[u],values[u]+sum);
         }
         return dp[u];
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>>adj(n);
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dp.assign(n,0);
        sub.assign(n,0);
        return dfs(0,-1,adj,values);
        // return dp[0];
    }
};