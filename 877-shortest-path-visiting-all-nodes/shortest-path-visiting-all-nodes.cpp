class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int N = 1<<n;
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        vector<vector<int>>dp(n,vector<int>(N,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            q.push({i,1<<i});
            dp[i][1<<i]=0;
        }
        while(!q.empty()){
            auto [u,mask] = q.front();q.pop();
            int d = dp[u][mask];
            if(mask == N-1) return d;
            for(int v:adj[u]){
                int nmask = mask|(1<<v);
                if(dp[v][nmask]==-1){
                    dp[v][nmask]=d+1;
                    q.push({v,nmask});
                }
            }
        }
        return -1;
    }
};