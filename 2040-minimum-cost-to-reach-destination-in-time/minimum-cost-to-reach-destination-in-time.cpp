class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>>adj(n);
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<vector<int>>dp(n,vector<int>(1001,INT_MAX));
        dp[0][0]=passingFees[0];
        using T = tuple<int,int,int>;
        priority_queue<T,vector<T>,greater<>>q;
        q.push({dp[0][0],0,0});
        while(!q.empty()){
            auto [d,t,u]=q.top();q.pop();
            if(dp[u][t]!=d) continue;
            for(auto [v,wt]:adj[u]){
                int nt = t+wt;
                if(nt<=maxTime && dp[v][nt]>d+passingFees[v]){
                    dp[v][nt]=d+passingFees[v];
                    q.push({dp[v][nt],nt,v});
                }
            }
        }
        int ans = *min_element(dp[n-1].begin(),dp[n-1].end());
        return ans==INT_MAX?-1:ans;
    }
};