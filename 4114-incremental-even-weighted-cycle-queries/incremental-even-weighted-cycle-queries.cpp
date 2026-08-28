class Solution {
public:
    struct DSU {
    vector<int> p, sz,parity;
    DSU(int n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);
        parity.assign(n+1,0);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if (p[x] == x) return x;
        int oldp = p[x];
        p[x] = find(p[x]);
        parity[x]^=parity[oldp];
        return p[x];
    }
    bool unite(int a, int b,int w) {
        int pa = find(a);
        int pb = find(b);
        if(sz[pa]<sz[pb]) swap(pb,pa);
        if(pa==pb) return (parity[a]^parity[b]^w==0);
        sz[pa]+=sz[pb];
        p[pb]=pa;
        parity[pb] = parity[a]^parity[b]^w;
        return true;
    }
};
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int ans=0;
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(dsu.unite(u,v,w)){
                ans++;
            }
        }
        return ans;
    }
};