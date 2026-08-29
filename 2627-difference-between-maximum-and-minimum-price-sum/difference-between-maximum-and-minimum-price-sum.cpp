class Solution {
public:
    #define ll long long
ll dfs1(int u,int par,vector<vector<int>>&adj,vector<int>&price,
        vector<ll>&down,vector<ll>&best1,vector<ll>&best2,
        vector<int>&child1,vector<int>&child2){

    ll mx1=0,mx2=0;
    int c1=-1,c2=-1;

    for(int v:adj[u]){
        if(v==par) continue;

        ll sum=dfs1(v,u,adj,price,down,best1,best2,child1,child2);

        if(sum>mx1){
            mx2=mx1;
            c2=c1;

            mx1=sum;
            c1=v;
        }
        else if(sum>mx2){
            mx2=sum;
            c2=v;
        }
    }

    best1[u]=mx1;
    best2[u]=mx2;
    child1[u]=c1;
    child2[u]=c2;

    down[u]=price[u]+mx1;

    return down[u];
}
void dfs2(int u,int par,vector<vector<int>>&adj,vector<int>&price,
          vector<ll>&up,vector<ll>&best1,vector<ll>&best2,
          vector<int>&child1){

    for(int v:adj[u]){
        if(v==par) continue;

        ll bestSibling;

        if(child1[u]!=v)
            bestSibling=best1[u];
        else
            bestSibling=best2[u];

        up[v]=price[v]+max(
            up[u],
            price[u]+bestSibling
        );

        dfs2(v,u,adj,price,up,best1,best2,child1);
    }
}
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<ll> best1(n),best2(n);
        vector<int> child1(n,-1),child2(n,-1);
        vector<ll>up(n,0),down(n,0);
        dfs1(0,-1,adj,price,down,best1,best2,child1,child2);
        dfs2(0,-1,adj,price,up,best1,best2,child1);
        ll ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,max(up[i],down[i])-price[i]);
        }
        return ans;
    }
};