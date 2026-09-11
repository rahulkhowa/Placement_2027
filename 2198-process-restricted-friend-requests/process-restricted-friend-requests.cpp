class Solution {
public:
    #define ll int
    #define pb push_back
    class DSU {
    public:
    vector<ll> parent, size,rank;
    DSU(ll n) {
        for(ll i=0;i<n;i++){
            size.pb(1);
            rank.pb(0);
            parent.pb(i);
        }
    }
    ll find(ll x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(ll x, ll y) {
        ll rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) swap(rootX, rootY);//X>Y
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
    bool unite1(ll x, ll y) {
        ll rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) swap(rootX, rootY);
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) rank[rootX]++;  // Fixing incorrect increment
            return true;
        }
        return false;
    }
    void simple_union(ll x,ll y){
       parent[find(x)]=find(y);
       // return;
    }
    bool same_set(ll x, ll y) {
        return find(x) == find(y);
    }
    ll get_size(ll x) {
        return size[find(x)];//included
    }
}; 
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DSU dsu(n);
        int m = requests.size();
        vector<bool>ans(m);
        for(int i=0;i<m;i++){
            int u = requests[i][0];
            int v = requests[i][1];
            int pu = dsu.find(u);
            int pv = dsu.find(v);
            bool flg=true;
            if(!dsu.same_set(pu,pv)){for(auto &r:restrictions){
                int u1 = r[0];
                int v1 = r[1];
                int pu1 = dsu.find(u1);
                int pv1 = dsu.find(v1);
                if((pu1==pu&&pv1==pv)||(pu1==pv&&pv1==pu)){
                    flg=false;
                    break;
                }
            }}
            ans[i]=flg;
            if(flg){
                dsu.unite(pu,pv);
            }
        }
        return ans;
    }
};