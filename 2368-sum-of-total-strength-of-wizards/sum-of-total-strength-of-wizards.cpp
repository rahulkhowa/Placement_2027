class Solution {
public:
    
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        vector<int>nums = strength;
        long long MOD = 1e9+7;
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
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top();
            }
            st.push(i);
        }
        long long ans=0;
        vector<long long>pre(n+1,0ll),ppre(n+2,0ll);
        for(int i=0;i<n;i++){
           pre[i+1] = (pre[i]+strength[i])%MOD;
        }
        for(int i=0;i<=n;i++){
            ppre[i+1]=(ppre[i]+pre[i])%MOD;
        }
        for(int i=0;i<n;i++){
            long long left = i-pse[i];
            long long right = nse[i]-i;
            ans+=((ppre[nse[i]+1]-ppre[i+1])*(left)%MOD+(MOD*2)-(ppre[i+1]-ppre[pse[i]+1])*(right)%MOD)%MOD*nums[i]%MOD;
            ans%=MOD;
        }
        return ans;
    }
};