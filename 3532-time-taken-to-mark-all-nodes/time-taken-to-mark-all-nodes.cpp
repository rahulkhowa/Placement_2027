class Solution {
public:
    int dfs1(int u,int par,vector<vector<int>>&adj,vector<int>&down,vector<int>&best1,
         vector<int>&best2,vector<int>&child1){
        int mx1=0,mx2=0;
        int ch=-1;
        for(int v:adj[u]){
            if(v==par) continue;
            int child = dfs1(v,u,adj,down,best1,best2,child1);
            if(child>mx1){
                mx2=mx1;
                mx1=child;
                ch=v;
            }
            else if(child>mx2){
                mx2=child;
            }
        }
        best1[u]=mx1;
        best2[u]=mx2;
        child1[u]=ch;
        down[u]=mx1+(u%2==0?2:1);
        return down[u];
    }
        void dfs2(int u,int par,vector<vector<int>>&adj,vector<int>&up,vector<int>&best1,
         vector<int>&best2,vector<int>&child1){
        for(int v:adj[u]){
            if(v==par) continue;
            int best;
            if(child1[u]!=v){
                best=best1[u];
            }
            else{
                best=best2[u];
            }
            up[v]=(v%2==0?2:1)+max(up[u],best+(u%2==0?2:1));
            dfs2(v,u,adj,up,best1,best2,child1);
        }
    }
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size();
        n++;
        vector<vector<int>>adj(n);
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>down(n,0),up(n,0),best1(n,-1),best2(n,-1),child1(n,-1);
        dfs1(0,-1,adj,down,best1,best2,child1);
        dfs2(0,-1,adj,up,best1,best2,child1);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
           ans[i]=max(up[i],down[i])-(i%2==0?2:1);
        }
        return ans;
    }
};