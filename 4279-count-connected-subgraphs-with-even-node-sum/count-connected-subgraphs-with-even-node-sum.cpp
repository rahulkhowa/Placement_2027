class Solution {
public:
    class DSU{
    vector<int> p;
    public:
    DSU(int n) {
        p.resize(n + 1);
        // sz.assign(n + 1, 1ll);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if (p[x] == x) return x;
        int oldp = p[x];
        return p[x] = find(p[x]);
    }
    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa==pb) return;
        p[pb]=pa;
    }
};
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int ans=0;
        int n = nums.size();
        int m = edges.size();
        int N = 1<<n;
        for(int mask=0;mask<N;mask++){
            DSU dsu(n);
            for(int j=0;j<m;j++){
                int u = edges[j][0];
                int v = edges[j][1];
                if((mask&(1<<u)) && (mask&(1<<v))){
                    dsu.unite(u,v);
                }
            }
            unordered_map<int,int>mp;
            for(int it=0;it<n;it++){
               if(mask&(1<<it)){
                  mp[dsu.find(it)]+=nums[it];
               }
            }
            if(mp.size()==1){
                for(auto e:mp){
                    if(e.second%2==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};