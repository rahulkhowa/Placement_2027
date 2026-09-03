class Solution {
public:
    int timer;
    vector<int>vis,tin,low;
    vector<vector<int>>ans,adj;
    void dfs(int u,int par){
       vis[u]=1;
       tin[u] = low[u] = timer++;
       for(int v:adj[u]){
          if(v==par) continue;
          if(!vis[v]){
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>tin[u]){
                ans.push_back({u,v});
            }
          }
          else{
            low[u]=min(low[u],tin[v]);
          }
       }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        timer=0;
        vis.assign(n,0),tin.assign(n,0),low.assign(n,0);
        adj.resize(n);
        for(auto c:connections){
            int u = c[0];
            int v = c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1);
            }
        }
        return ans;
    }
};