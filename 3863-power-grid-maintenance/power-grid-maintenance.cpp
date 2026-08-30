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
            if(px==py) return;
            if (sz[px] < sz[py])
                swap(px, py);
            par[py] = px;
            sz[px] += sz[py];
        }
        int getsize(int x){
            return sz[find(x)];
        }
    };
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for(auto e:connections){
            int u = e[0]-1;
            int v = e[1]-1;
            dsu.unite(u,v);
        }
        map<int,set<int>>st;
        for(int i=0;i<c;i++){
            st[dsu.find(i)].insert(i);
        }
        vector<int>ans;
        for(auto q:queries){
            int type = q[0];
            int i = q[1]-1;
            int par = dsu.find(i);
            if(type==1){
                if(st[par].contains(i)){
                    ans.push_back(i+1);
                    // st[par].erase(i);
                }
                else if(!st[par].empty()){
                    auto it = st[par].begin();
                    ans.push_back((*it)+1);
                    // st[par].erase(it);
                }
                else{
                    ans.push_back(-1);
                }
            }
            else{
                 st[par].erase(i);
            }
        }
        return ans;
    }
};