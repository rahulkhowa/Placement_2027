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
            if (px == py)
                return;
            if (sz[px] < sz[py])
                swap(px, py);
            par[py] = px;
            sz[px] += sz[py];
        }
        int getsize(int x) { return sz[find(x)]; }
    };
    int ind(int x, int y) { return y + (x * m) + 1; }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        m = col;
        DSU dsu((row * col) + 2);
        int top = 0;
        int bottom = (row * col) + 1;
        vector<vector<int>> grid(row, vector<int>(col, 1));
        // reverse(cells.begin(),cells.end());
        vector<vector<int>> dis = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = cells.size()-1; i>=0 ; i--) {
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;
            grid[x][y] = 0;
            if (x == 0) {
                dsu.unite(top, ind(x, y));
            }
            if (x == row - 1) {
                dsu.unite(bottom, ind(x, y));
            }
            for (int k = 0; k < 4; k++) {
                int nx = x + dis[k][0];
                int ny = y + dis[k][1];
                if (nx >= 0 && ny >= 0 && nx < row && ny < col && !grid[nx][ny]) {
                    dsu.unite(ind(x, y), ind(nx, ny));
                }
            }
            if (dsu.find(top) == dsu.find(bottom)) {
                return i;
            }
        }
        return 0;
    }
};