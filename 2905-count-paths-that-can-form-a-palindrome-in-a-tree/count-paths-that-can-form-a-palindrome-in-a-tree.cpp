class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=1;i<n;i++){
            adj[i].push_back({parent[i],s[i]-'a'});
            adj[parent[i]].push_back({i,s[i]-'a'});
        }
        unordered_map<int,long long>mask;
        stack<tuple<int,int,int>>st;
        long long ans=0;
        st.push({0,-1,0});// u par mask
        while(!st.empty()){
            auto [u,par,m] = st.top();st.pop();
            ans+=mask[m];
            for(int i=0;i<26;i++){
                int nm = m^(1<<i);
                ans+=mask[nm];
            }
            mask[m]++;
            for(auto [v,w]:adj[u]){
                if(v==par) continue;
                int nm = m^(1<<w);
                st.push({v,u,nm});
            }
        }
        return ans;
    }
};