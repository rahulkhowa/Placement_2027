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
    };
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rank(n + m, 0);
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[matrix[i][j]].push_back({i, j});
            }
        }
        for (auto e : mp) { // increasing order of values
            DSU dsu(n + m);
            for (auto [i, j] : e.second) {
                dsu.unite(i, j + n);
            }
            unordered_map<int,int>mx;
            unordered_map<int, vector<int>> comp;
            for (auto [i, j] : e.second) {
                comp[dsu.find(i)].push_back(i);
                comp[dsu.find(i)].push_back(j + n);
            }
            for (auto e1 : comp) {
                for (int x : e1.second) {
                    mx[e1.first] = max(mx[e1.first], rank[x]);
                }
            }
            for (auto e1 : comp) {
                for (int x : e1.second) {
                    rank[x] = mx[e1.first] + 1;
                }
            }
            for (auto [i, j] : e.second) {
                matrix[i][j] = rank[j + n];
            }
        }
        return matrix;
    }
};