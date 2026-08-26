class Solution {
public:
        class DSU{
        private:
        vector<int>par,rank;
        public:
        DSU(int n){
            par.resize(n),rank.resize(n,0);
            for(int i=0;i<n;i++){
                par[i]=i;
            }
        }
        int find(int x){
            if(x==par[x]) return x;
            return par[x]=find(par[x]);
        }
        void unite(int x,int y){
            int px = find(x);
            int py = find(y);
            if(px==py) return;
            if(rank[px]<rank[py]){
                swap(px,py);
            }
            par[py]=px;
            if(rank[px]==rank[py]){
                rank[px]++;
            }
        }
    };
    vector<int>spf(int N){
        vector<int>ans(N+1,-1);
        for(int i=2;i<=N;i++){
            ans[i]=i;
        }
        for(int i=2;i*i<=N;i++){
            if(ans[i]==i){
                for(int j=i;j<=N;j+=i){
                    ans[j]=i;
                }
            }
        }
        return ans;
    }
    vector<int>prime(vector<int>&nums){
        int N = 1e5;
        vector<int>sp = spf(N);
        set<int>st;
        for(int x:nums){
            int y = sp[x];
            while(x>1){
                st.insert(y);
                while(x%y==0){
                    x/=y;
                }
                y=sp[x];
            }
        }
        vector<int>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
    int largestComponentSize(vector<int>& nums) {
        vector<int>p = prime(nums);
        int N = 1e5; 
        DSU dsu(N+1);
        unordered_map<int,int>st;
        for(int i=0;i<nums.size();i++){
           st[nums[i]]=i;
        }
        for(int x:p){
           for(int j=x;j<=N;j+=x){
              if(st.count(j)){
                dsu.unite(j,x);
              }
           }
        }
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[dsu.find(x)]++;
        }
        int ans = 1;
        for(auto e:mp){
            ans=max(ans,e.second);
        }
        return ans;
    }
};