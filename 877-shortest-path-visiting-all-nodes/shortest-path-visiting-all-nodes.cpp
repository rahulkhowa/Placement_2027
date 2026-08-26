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
        vector<vector<int>>vis(N,vector<int>(n,0));
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            q.push({i,1<<i,0});
            vis[1<<i][i]=1;
        }
        while(!q.empty()){
            auto [u,mask,d] = q.front();q.pop();
            if(mask == N-1) return d;
            for(int v:adj[u]){
                int nmask = mask|(1<<v);
                if(!vis[nmask][v]){
                    vis[nmask][v]=1;
                    q.push({v,nmask,d+1});
                }
            }
        }
        return -1;
    }
};