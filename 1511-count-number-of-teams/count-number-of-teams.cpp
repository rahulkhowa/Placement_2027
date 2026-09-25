class Solution {
public:
    class SegmentTree {
    private:
        vector<int> tree, arr;
        int n;
        void build(int node, int l, int r) {
            if (l == r) {
                tree[node] = 0;
                return;
            }
            int mid = (l + r) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
        int query(int node, int l, int r, int ql, int qr) {
            if (ql > r || qr < l) {
                return neutral();
            }
            if (ql <= l && qr >= r) {
                return tree[node];
            }
            int mid = (l + r) / 2;
            int left = query(2 * node, l, mid, ql, qr);
            int right = query(2 * node + 1, mid + 1, r, ql, qr);
            return merge(left, right);
        }
        void update(int node, int l, int r, int idx, int val) {
            if (l == r) {
                tree[node] = val;
                return;
            }
            int mid = (l + r) / 2;
            if (idx <= mid) {
                update(2 * node, l, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, r, idx, val);
            }
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
        int merge(int a, int b) { return a + b; }
        int neutral() { return 0; }

    public:
        SegmentTree(vector<int>& arr) {
            int n = arr.size();
            this->arr = arr;
            this->n = n;
            tree.resize(4 * n);
            build(1, 0, n - 1);
        }
        void update(int idx, int val) { update(1, 0, n - 1, idx, val); }
        int query(int l, int r) { return query(1, 0, n - 1, l, r); }
    };
    int numTeams(vector<int>& rating) {
        vector<int> sorted = rating;
        sort(sorted.begin(), sorted.end());
        int n = rating.size();
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            int it = lower_bound(sorted.begin(), sorted.end(), rating[i]) -
                     sorted.begin();
            pos[i] = it;
        }
        vector<int> lsm(n), lg(n), rsm(n), rg(n);
        SegmentTree sgt1(rating), sgt2(rating);
        for (int i = 0; i < n; i++) {
            int x = pos[i];
            lsm[i] = sgt1.query(0, x - 1);
            lg[i] = sgt1.query(x + 1, n - 1);
            sgt1.update(x, 1);
        }
        for (int i = n - 1; i >= 0; i--) {
            int x = pos[i];
            rsm[i] = sgt2.query(0, x - 1);
            rg[i] = sgt2.query(x + 1, n - 1);
            sgt2.update(x, 1);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (lsm[i] * rg[i]);
            ans += (lg[i] * rsm[i]);
        }
        return ans;
    }
};