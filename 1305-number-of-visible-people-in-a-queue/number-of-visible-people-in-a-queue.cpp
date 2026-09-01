class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            while(!st.empty() && heights[st.top()]<=heights[i]){
                cnt++;
                st.pop();
            }
            if(!st.empty()){
                ans[i]=cnt+1;
            }
            else{
                ans[i]=cnt;
            }
            st.push(i);
        }
        return ans;
    }
};