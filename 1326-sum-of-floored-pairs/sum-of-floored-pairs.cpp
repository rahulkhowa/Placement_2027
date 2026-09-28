class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> cnt(mx + 1, 0), pref(mx + 1, 0);

        for (int x : nums)
            cnt[x]++;

        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + cnt[i];

        long long ans = 0;

        for (int y = 1; y <= mx; y++) {
            if (cnt[y] == 0) continue;

            for (int d = 1; d * y <= mx; d++) {
                int l = d * y;
                int r = min(mx, (d + 1) * y - 1);

                int amount = pref[r] - pref[l - 1];

                ans = (ans + 1LL * cnt[y] * d * amount) % MOD;
            }
        }

        return ans;
    }
};