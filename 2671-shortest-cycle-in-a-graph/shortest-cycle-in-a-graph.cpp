class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = n+1;
        for(int i=0;i<n;i++){
            queue<int>q;
            q.push(i);
            vector<int>dist(n,-1),par(n,-1);
            dist[i]=1;
            while(!q.empty()){
                auto u = q.front();q.pop();
                for(int v:adj[u]){
                   if(dist[v]==-1){
                      dist[v]=dist[u]+1;
                      par[v]=u;
                      q.push(v);
                   }
                   else if(v!=par[u]){
                     ans=min(ans,dist[u]+dist[v]-1);
                   }
                }
            }
        }
        return ans==n+1?-1:ans;
    }
};