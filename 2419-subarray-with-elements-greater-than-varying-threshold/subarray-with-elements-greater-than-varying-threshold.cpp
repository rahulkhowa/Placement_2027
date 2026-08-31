class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        stack<int>st;
        vector<int>nse(n,n),pse(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top();
            }
            st.push(i);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int left = pse[i]+1;
            int right = nse[i]-1;
            ans[i]=right-left+1;
        }
        for(int i=0;i<n;i++){
            float k = threshold/ans[i];
            if((float)nums[i]>k){
                return ans[i];
            }
        }
        return -1;
    }
};