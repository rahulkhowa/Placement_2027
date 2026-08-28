class Solution {
public:
    vector<int>path;
    void heirholzer(int u,unordered_map<int,vector<int>>&adj){
        while(!adj[u].empty()){
           int v = adj[u].back();
           adj[u].pop_back();
           heirholzer(v,adj);
        }
        path.push_back(u);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>in,out;
        // set<int>st;
        for(auto p:pairs){
            int u = p[0];
            int v = p[1];
            adj[u].push_back(v);
            // adj[v].push_back(u);
            in[v]++;
            out[u]++;
        }
        int start=-1;
        for(auto o:out){
            int ind = in[o.first];
            int outd = o.second;
            if(outd==ind+1){
                start=o.first;
                break;
            }
        }
        if(start==-1){
              for(auto o:out){
            // int ind = in[o.first];
            int outd = o.second;
            if(outd>0){
                start=o.first;
                break;
            }
           }
        }
        heirholzer(start,adj);
        vector<vector<int>>ans;
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size()-1;i++){
            ans.push_back({path[i],path[i+1]});
        }
        return ans;
    }
};