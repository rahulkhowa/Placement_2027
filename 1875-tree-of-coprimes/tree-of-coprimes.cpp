class Solution {
public:
    void dfs1(int u,int par,vector<vector<int>>&adj,int d,vector<int>&dep){
        dep[u]=d;
        for(int v:adj[u]){
            if(v==par) continue;
            dfs1(v,u,adj,d+1,dep);
        }
    }
void dfs2(int u, int par, int anc,
          vector<vector<int>>& adj,
          int val,
          vector<int>& nums,
          vector<int>& dep,
          vector<int>& ans) {

    // FIRST check the previous ancestor
    if(anc != -1 && __gcd(nums[u], val) == 1) {

        if(ans[u] == -1 || dep[anc] > dep[ans[u]]) {
            ans[u] = anc;
        }
    }

    // THEN current node becomes the ancestor for children
    if(nums[u] == val) {
        anc = u;
    }

    for(int v : adj[u]) {

        if(v == par)
            continue;

        dfs2(v, u, anc, adj, val,
             nums, dep, ans);
    }
}
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dep(n,-1);
        dfs1(0,-1,adj,0,dep);
        vector<int>ans(n,-1);
        for(int val=1;val<=50;val++){
            dfs2(0,-1,-1,adj,val,nums,dep,ans);
        }
        return ans;
    }
};