class Solution {
public:
    using ll = long long;

    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n = items.size();

        sort(items.rbegin(), items.rend());

        ll sum = 0;
        ll ans = 0;

        unordered_map<int, int> freq;

        // {profit, category}
        // Contains only removable items:
        // items whose category has appeared at least twice.
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > removable;

        int distinct = 0;

        // Initial k items
        for (int i = 0; i < k; i++) {
            int profit = items[i][0];
            int category = items[i][1];

            sum += profit;

            if (freq[category] == 0) {
                distinct++;
            } else {
                removable.push({profit, category});
            }

            freq[category]++;
        }

        ans = sum + 1LL * distinct * distinct;

        // Try to introduce new categories
        for (int i = k; i < n; i++) {
            int profit = items[i][0];
            int category = items[i][1];

            // Category already exists
            if (freq[category] > 0)
                continue;

            // No duplicate-category item to remove
            if (removable.empty())
                break;

            auto [oldProfit, oldCategory] = removable.top();
            removable.pop();

            sum -= oldProfit;
            sum += profit;

            freq[oldCategory]--;
            freq[category]++;

            distinct++;

            ans = max(
                ans,
                sum + 1LL * distinct * distinct
            );
        }

        return ans;
    }
};