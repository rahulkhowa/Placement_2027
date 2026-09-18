class Solution {
public:
    vector<int>v,visc;
    vector<vector<pair<int,int>>>adj;
    int ans;
    int mxt;
    void dfs(int u,int currt,int sum){
        if(visc[u]==0){
            sum+=v[u];
        }
        visc[u]++;
        if(u==0){
            ans=max(ans,sum);
        }
        for(auto [v,tt]:adj[u]){
            if(currt+tt<=mxt){
                dfs(v,currt+tt,sum);
            }
        }
        visc[u]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        v=values;
        mxt=maxTime;
        visc.assign(n,0);
        adj.resize(n);
        ans=0;
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            int t = e[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        dfs(0,0,0);
        return ans;
    }
};