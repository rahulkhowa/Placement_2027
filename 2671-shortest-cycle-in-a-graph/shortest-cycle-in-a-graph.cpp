class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto& e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int mini=1e9;
        for(int i=0;i<n;i++){
            vector<int>dist(n,-1);
            vector<int>par(n,-1);
            queue<int>q;
            dist[i]=1;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto& padosi:adj[node]){
                    if(dist[padosi]==-1){
                        dist[padosi]=dist[node]+1;
                        par[padosi]=node;
                        q.push(padosi);
                    }else if(padosi!=par[node]){
                        mini=min(mini,dist[padosi]+dist[node]-1);
                    }
                }

            }
        }
        return (mini==1e9)?-1:mini;
    }
};