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
    bool gcdSort(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        vector<int>p = prime(nums);
        int N = 1e5; 
        DSU dsu(N+1);
        multiset<int>st(nums.begin(),nums.end());
        for(int x:p){
           for(int j=x;j<=N;j+=x){
              if(st.find(j)!=st.end()){
                dsu.unite(j,x);
              }
           }
        }
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[dsu.find(nums[i])].push_back(i);
        }
        vector<int>ans(nums.size(),-1);
        for(auto e:mp){
            vector<int>tmp;
            for(int ind:e.second){
                tmp.push_back(nums[ind]);
            }
            sort(tmp.begin(),tmp.end());
            int i = 0;
            for(int ind:e.second){
                ans[ind]=tmp[i++];
            }
        }
        if(is_sorted(ans.begin(),ans.end())){
            return true;
        }
        return false;
    }
};