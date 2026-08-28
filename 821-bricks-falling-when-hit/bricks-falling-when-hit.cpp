class Solution {
public:
    int m;
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
    int ind(int x,int y){
        return y+(x*m)+1;
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n = grid.size();
        int m1 = grid[0].size();
        m=m1;
        vector<vector<int>>valid(n,vector<int>(m,0));
        for(int i=0;i<hits.size();i++){
            int x = hits[i][0];
            int y = hits[i][1];
            if(grid[x][y]==1){
                valid[x][y]=1;
            }
            grid[x][y]=0;
        }
        //virtual top be 0
        DSU dsu((n*m)+1);
        vector<vector<int>>dis = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                if(i==0){
                    dsu.unite(ind(i,j),0);
                }
                for(int k=0;k<4;k++){
                    int ni = i+dis[k][0];
                    int nj = j+dis[k][1];
                    if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1){
                       dsu.unite(ind(i,j),ind(ni,nj));
                    }
                }
            }
        }
        vector<int>ans(hits.size(),-1);
        for(int i=hits.size()-1;i>=0;i--){
            int u = hits[i][0];
            int v = hits[i][1];
            if(!valid[u][v]){
                ans[i]=0;
                continue;
            }
            int before = dsu.getsize(0);
            grid[u][v]=1;
            if(u==0){
                dsu.unite(ind(u,v),0);
            }
            for(int k=0;k<4;k++){
                int nu = u+dis[k][0];
                int nv = v+dis[k][1];
                if(nu>=0 && nv>=0 && nu<n && nv<m && grid[nu][nv]==1){
                    dsu.unite(ind(u,v),ind(nu,nv));
                }
            }
            int after = dsu.getsize(0);
            ans[i]=max(0,after-before-1);
        }
        return ans;
    }
};