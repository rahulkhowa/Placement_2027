class Solution {
public:
    class DSU {
        vector<int> sz, par;
        unordered_map<int, vector<int>> comp;
        int n;

    public:
        DSU(int n) {
            this->n = n;
            sz.resize(n), par.resize(n);
            for (int i = 0; i < n; i++) {
                par[i] = i;
                sz[i] = 1;
            }
        }
        int find(int x) {
            if (x == par[x])
                return x;
            return par[x] = find(par[x]);
        }
        void unite(int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px == py)
                return;
            if (sz[px] < sz[py])
                swap(px, py);
            par[py] = px;
            sz[px] += sz[py];
        }
        int getsize(int x) { return sz[find(x)]; }
    };
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU dsu(n);
        sort(edgeList.begin(),edgeList.end(),[&](vector<int>e1,vector<int>e2){
            return e1[2]<e2[2];
        });
        vector<vector<int>>q;
        for(int i=0;i<queries.size();i++){
            q.push_back(queries[i]);
            reverse(q[i].begin(),q[i].end());
            q[i].push_back(i);
        }
        sort(q.begin(),q.end());
        int i=0;
        vector<bool>ans(q.size(),false);
        for(int j=0;j<q.size();j++){
            while(i<edgeList.size() && edgeList[i][2]<q[j][0]){
                dsu.unite(edgeList[i][1],edgeList[i][0]);
                i++;
            }
            ans[q[j][3]]=(dsu.find(q[j][1])==dsu.find(q[j][2]));
        }
        return ans;
    }
};