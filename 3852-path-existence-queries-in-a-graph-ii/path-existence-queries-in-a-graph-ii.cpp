class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums,
                                     int maxDiff, vector<vector<int>>& queries) {
        int LOG = 20;

        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        vector<int> val(n), pos(n);
        for (int i = 0; i < n; i++) {
            val[i] = a[i].first;
            pos[a[i].second] = i;
        }

        // nxt[i] = farthest position reachable in one edge
        vector<vector<int>> up(n, vector<int>(LOG));
        int r = 0;

        for (int i = 0; i < n; i++) {
            r = max(r, i);

            while (r + 1 < n && val[r + 1] - val[i] <= maxDiff)
                r++;

            up[i][0] = r;
        }

        // Binary lifting
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;

        for (auto& q : queries) {
            int l = pos[q[0]];
            int rr = pos[q[1]];

            if (l > rr)
                swap(l, rr);

            if (l == rr) {
                ans.push_back(0);
                continue;
            }

            int steps = 0;

            // Make the largest possible jumps without reaching rr
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[l][j] < rr) {
                    l = up[l][j];
                    steps += (1 << j);
                }
            }

            // Can we reach rr in one more edge?
            if (up[l][0] >= rr)
                ans.push_back(steps + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};