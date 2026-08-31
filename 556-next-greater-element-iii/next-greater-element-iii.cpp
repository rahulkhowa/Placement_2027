class Solution {
public:
    int nextGreaterElement(int n) {
        string ans = to_string(n);
        next_permutation(ans.begin(),ans.end());
        long long INT_ans = stoll(ans);
        if(INT_ans>INT_MAX||INT_ans<=n) return -1;
        return (int)INT_ans;
    }
};