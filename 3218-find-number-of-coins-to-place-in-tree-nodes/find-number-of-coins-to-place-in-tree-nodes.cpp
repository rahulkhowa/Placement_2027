class Solution {
public:
    vector<long long> ans;
    vector<int> sub;

    void dfs(int u,int par,vector<vector<int>>& adj){
        sub[u]=1;

        for(int v:adj[u]){
            if(v==par) continue;

            dfs(v,u,adj);
            sub[u]+=sub[v];
        }
    }

    vector<long long> dfs2(int u,int par,vector<vector<int>>& adj,vector<int>& cost){
        vector<long long> a;
        a.push_back(cost[u]);

        for(int v:adj[u]){
            if(v==par) continue;

            vector<long long> b=dfs2(v,u,adj,cost);

            for(long long x:b)
                a.push_back(x);
        }

        sort(a.begin(),a.end());

        if(a.size()>5){
            vector<long long> b;

            b.push_back(a[0]);
            b.push_back(a[1]);

            int n=a.size();

            b.push_back(a[n-3]);
            b.push_back(a[n-2]);
            b.push_back(a[n-1]);

            a=b;
        }

        if(sub[u]<3){
            ans[u]=1;
        }
        else{
            int n=a.size();

            long long p=0;

            // 3 largest
            p=max(p,a[n-1]*a[n-2]*a[n-3]);

            // 2 smallest + largest
            if(n>=3)
                p=max(p,a[0]*a[1]*a[n-1]);

            ans[u]=p;
        }

        return a;
    }

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n=cost.size();

        vector<vector<int>> adj(n);

        for(auto e:edges){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        sub.assign(n,0);
        ans.assign(n,0);

        dfs(0,-1,adj);
        dfs2(0,-1,adj,cost);

        return ans;
    }
};