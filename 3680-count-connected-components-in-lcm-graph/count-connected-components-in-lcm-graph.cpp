class Solution {
public:
    int thresh;
    class DSU{
      private:
      vector<int>sz,rank,parent;
      public:
      DSU(int n){
        sz.resize(n),parent.resize(n),rank.resize(n);
        for(int i=0;i<n;i++){
            sz[i]=0;
            parent[i]=i;
            rank[i]=0;
        }
      }
      int find(int x){
         if(x==parent[x]) return x;
         return parent[x]=find(parent[x]);
      }
      void unite(int x,int y){
        int px = find(x);
        int py = find(y);

        if(px == py)
            return;

        // attach smaller rank under larger rank
        if(rank[px] < rank[py]) {
            swap(px, py);
        }

        parent[py] = px;

        // ranks increase only when both ranks are equal
        if(rank[px] == rank[py]) {
            rank[px]++;
        }
      }
    };
    int lcm(int x,int y){
        int hcf = __gcd(x,y);
        return ((x*y)/hcf);
    }
    int countComponents(vector<int>& nums, int threshold) {
        thresh = threshold;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        DSU dsu(threshold+1);
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(x<=threshold){for(int j=x;j<=threshold;j+=x){
                dsu.unite(x,j);
            }}
            else{
                ans++;
            }
        }
        for(int x:nums){
            if(x<=threshold)
            mp[dsu.find(x)]++;
        }
        return ans+(int)mp.size();
    }
};