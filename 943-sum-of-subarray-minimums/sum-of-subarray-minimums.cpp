class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long MOD = 1e9 + 7;
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n, n), pse(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long curr = arr[i] % MOD;
            curr = curr * left % MOD;
            curr = curr * right % MOD;

            ans = (ans + curr) % MOD;
        }
        return (int)ans;
    }
};