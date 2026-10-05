class Solution {
public:
    #define ll long long

    int maxPerformance(int n, vector<int>& speed,
                       vector<int>& efficiency, int k) {

        const ll MOD = 1e9 + 7;

        vector<pair<ll,ll>> v;

        for(int i = 0; i < n; i++) {
            v.push_back({efficiency[i], speed[i]});
        }

        // Efficiency decreasing
        sort(v.rbegin(), v.rend());

        priority_queue<ll, vector<ll>, greater<ll>> pq;

        ll sum = 0;
        ll ans = 0;

        for(int i = 0; i < n; i++) {

            ll e = v[i].first;
            ll s = v[i].second;

            pq.push(s);
            sum += s;

            // Keep only k largest speeds
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            ans = max(ans, sum * e);
        }

        return ans % MOD;
    }
};