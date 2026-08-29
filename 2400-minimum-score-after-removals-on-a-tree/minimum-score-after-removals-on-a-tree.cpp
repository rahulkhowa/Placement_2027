class Solution {
public:
    int dfs1(int u,int par,vector<int>&nums,vector<vector<int>>&adj,vector<int>&xor1){
        int x=0;
        for(int v:adj[u]){
            if(v==par) continue;
            x^=dfs1(v,u,nums,adj,xor1);
        }
        xor1[u]=(x^nums[u]);
        return xor1[u];
    }
class LCA{
        private:
        int n,N,timer;
        vector<vector<int>>up;
        vector<int>depth,tin,tout;
        vector<vector<int>>adj;
        void dfs(int u,int par,int d){
            depth[u]=d;
            tin[u]=timer++;
            up[u][0] = par;
            for(int i=1;i<N;i++){
                up[u][i]=up[up[u][i-1]][i-1];
            }
            for(int v:adj[u]){
                if(v==par) continue;
                dfs(v,u,d+1);
            }
            tout[u]=timer++;
        }
        public:
        LCA(int n){
            this->n = n;
            N = 1;
            while((1<<N)<=n){
                N++;
            }
            adj.resize(n);
            up.assign(n,vector<int>(N));
            depth.assign(n,0);
            tin.resize(n),tout.resize(n);
            timer=0;
        }
        void add(int u,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void build(int root=0){
            dfs(root,root,0);
        }
        bool isancestor(int u,int v){
            return (tin[u]<=tin[v] && tout[u]>=tout[v]);
        }
        int kth_ancestor(int u,int k){
            for(int i=0;i<N;i++){
                if(k&(1<<i)){
                    u=up[u][i];
                }
            }
            return u;
        }
        int lca(int u,int v){
            if(isancestor(u,v)){
                return u;
            }
            if(isancestor(v,u)){
                return v;
            }
            for(int i=N-1;i>=0;i--){
                if(!isancestor(up[u][i],v)){
                    u=up[u][i];
                }
            }
            return up[u][0];
        }
        int distance(int u,int v){
            int l = lca(u,v);
            return depth[u]+depth[v]-2*depth[l];
        }
        int kth_node(int u,int v,int k){
           int l = lca(u,v);
           int du = depth[u]-depth[l];
           int dv = depth[v]-depth[l];
           if(k<=du){
               return kth_ancestor(u,k);
           }
           int rem = du+dv-k;
           return kth_ancestor(v,k);
        }
        int getd(int u){
            return depth[u];
        }
    };
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        LCA lca(n);
        vector<int>xor1;
        xor1.assign(n,0);
        vector<vector<int>>adj(n);
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            lca.add(u,v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        lca.build();
        int x = dfs1(0,-1,nums,adj,xor1);
        int ans = INT_MAX;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n-1;j++){
                int u1 = edges[i][0];
                int v1 = edges[i][1];
                int u2 = edges[j][0];
                int v2 = edges[j][1];
                if(lca.getd(u1)<lca.getd(v1)) swap(u1,v1);
                if(lca.getd(u2)<lca.getd(v2)) swap(u2,v2);
                vector<int>tmp = {xor1[u1],xor1[u2],xor1[u1]^xor1[u2]^x};
                if(lca.isancestor(u1,u2)){
                    tmp[0]^=tmp[1];
                    tmp[2]=tmp[0]^tmp[1]^x;
                }
                if(lca.isancestor(u2,u1)){
                    tmp[1]^=tmp[0];
                    tmp[2]=tmp[0]^tmp[1]^x;
                }
                sort(tmp.begin(),tmp.end());
                if(tmp[2]-tmp[0]<ans){
                    ans=tmp[2]-tmp[0];
                    cout<<i<<" "<<j<<endl;
                    cout<<u1<<" "<<u2<<endl;
                }
            }
        }
        return ans;
    }
};