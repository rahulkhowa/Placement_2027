class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1),vis(n,0);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int u = q.front();q.pop();
                    if(vis[u]) continue;
                    vis[u]=1;
                    for(int v:graph[u]){
                        if(vis[v]) continue;
                        if(color[u]==color[v]) return false;
                        if(color[v]==-1){
                            color[v]=color[u]^1;
                            q.push(v);
                        }
                    }
                }
            }
        }
        return true;
    }
};