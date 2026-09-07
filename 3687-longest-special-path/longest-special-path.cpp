class Solution {
public:
    using ll = long long;

    vector<vector<pair<int, int>>> adj;
    vector<int> nums;

    unordered_map<int, int> last;
    vector<ll> pathDist;

    ll ansLen = 0;
    int ansNodes = INT_MAX;

    void dfs(int u, int parent, int depth, int left) {

        int x = nums[u];

        int oldLeft = left;

        if (last.count(x)) {
            left = max(left, last[x] + 1);
        }

        // Distance of special path
        ll len = pathDist[depth] - pathDist[left];

        // Number of nodes
        int nodes = depth - left + 1;

        if (len > ansLen) {
            ansLen = len;
            ansNodes = nodes;
        } else if (len == ansLen) {
            ansNodes = min(ansNodes, nodes);
        }

        int oldLast = -1;

        if (last.count(x))
            oldLast = last[x];

        last[x] = depth;

        for (auto [v, w] : adj[u]) {
            if (v == parent)
                continue;

            pathDist.push_back(pathDist.back() + w);

            dfs(v, u, depth + 1, left);

            pathDist.pop_back();
        }

        if (oldLast == -1)
            last.erase(x);
        else
            last[x] = oldLast;
    }

    vector<int> longestSpecialPath(vector<vector<int>>& edges,
                                   vector<int>& nums) {
        int n = nums.size();

        this->nums = nums;
        adj.assign(n, {});

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        pathDist.push_back(0);

        dfs(0, -1, 0, 0);

        return {(int)ansLen, ansNodes};
    }
};