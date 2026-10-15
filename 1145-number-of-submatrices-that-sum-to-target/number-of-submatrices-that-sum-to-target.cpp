class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;

        for (int top = 0; top < n; top++) {
            vector<int> col(m, 0);

            for (int bottom = top; bottom < n; bottom++) {
                for (int j = 0; j < m; j++)
                    col[j] += matrix[bottom][j];

                unordered_map<int, int> freq;
                freq[0] = 1;
                int sum = 0;

                for (int x : col) {
                    sum += x;
                    ans += freq[sum - target];
                    freq[sum]++;
                }
            }
        }

        return ans;
    }
};