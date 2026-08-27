class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int>mask(n,0);
        vector<vector<pair<int,int>>>adj(n);
        for(int i=1;i<n;i++){
            // adj[i].push_back({parent[i],s[i]-'a'});
            adj[parent[i]].push_back({i,s[i]-'a'});
        }
        queue<int>q;
        q.push(0);
        while(!q.empty()){
           int u = q.front();q.pop();
           for(auto [v,w]:adj[u]){
              mask[v] = mask[u]^(1<<w);
              q.push(v);
           }
        }
        long long ans=0;
        unordered_map<int,long long>mp;
        for(int i=0;i<n;i++){
             ans+=mp[mask[i]];
             for(int j=0;j<26;j++){
                ans+=mp[mask[i]^(1<<j)];
             }
             mp[mask[i]]++;
        }
        return ans;
    }
};