class Solution {
public:
    void dfs(int u,vector<vector<int>>&adj,set<int>&st,vector<int>&nums){
        st.erase(nums[u]);
        for(int v:adj[u]){
            if(st.count(nums[v])){
                dfs(v,adj,st,nums);
            }
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>adj(n);
        int mx = *max_element(nums.begin(),nums.end());
        set<int>st;
        for(int i=1;i<=mx+1;i++){
            st.insert(i);
        }
        // st.insert(n+1);
        for(int i=1;i<n;i++){
            adj[parents[i]].push_back(i);
        }
        int u = -1;
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
           if(nums[i]==1){
             u = i;
             break;
           }
        }
        if(u==-1) return ans;
        while(u!=-1){
            dfs(u,adj,st,nums);
            ans[u]=*st.begin();
            u=parents[u];
        }
        return ans;
    }
};