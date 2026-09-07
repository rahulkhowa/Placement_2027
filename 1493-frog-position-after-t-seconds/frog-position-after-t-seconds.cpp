class Solution {
public:
    #define dl double
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<dl>prob(n,0.0);
        vector<vector<int>>adj(n);
        for(auto e:edges){
            int u = e[0];
            int v = e[1];;
            --u;--v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        vis[0]=1;
        prob[0]=1.0;
        while(!q.empty() && (t--)>0){
            for(int sz=q.size();sz>0;sz--){int u = q.front();q.pop();
            int nxtc = 0;
            for(int v:adj[u]){
                if(!vis[v]){
                    nxtc++;
                }
            }
            for(int v:adj[u]){
                if(!vis[v]){
                    vis[v]=1;
                    prob[v]=prob[u]/nxtc;
                    q.push(v);
                }
            }
            if(nxtc>0) prob[u]=0;}
        }
        return prob[target-1];
    }
};