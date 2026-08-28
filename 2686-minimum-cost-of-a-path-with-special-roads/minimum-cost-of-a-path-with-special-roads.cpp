class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        map<pair<int,int>,vector<vector<int>>>adj;
        int n = specialRoads.size();
        set<pair<int,int>>st;
        for(int i=0;i<n;i++){
            int x1 = specialRoads[i][0];
            int y1 = specialRoads[i][1];
            int x2 = specialRoads[i][2];
            int y2 = specialRoads[i][3];
            int c = specialRoads[i][4];
            st.insert({x1,y1});
            st.insert({x2,y2});
        }
        vector<pair<int,int>>edge1;
        for(auto it:st){
            edge1.push_back(it);
        }
        int m = edge1.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i!=j){
                    vector<int>tmp;
                    tmp.push_back(edge1[j].first);
                    tmp.push_back(edge1[j].second);
                    tmp.push_back(abs(edge1[i].first-edge1[j].first)+abs(edge1[i].second-edge1[j].second));
                    adj[edge1[i]].push_back(tmp);
                }
            }
        }
        for(int i=0;i<n;i++){
            int x1 = specialRoads[i][0];
            int y1 = specialRoads[i][1];
            int x2 = specialRoads[i][2];
            int y2 = specialRoads[i][3];
            int c = specialRoads[i][4];
            pair<int,int>s = {start[0],start[1]};
            pair<int,int>t = {target[0],target[1]};
            adj[s].push_back({x1,y1,abs(s.first-x1)+abs(s.second-y1)});
            adj[s].push_back({x2,y2,abs(s.first-x2)+abs(s.second-y2)});
            adj[{x1,y1}].push_back({t.first,t.second,abs(x1-t.first)+abs(y1-t.second)});
            adj[{x2,y2}].push_back({t.first,t.second,abs(x2-t.first)+abs(y2-t.second)});
            adj[{x1,y1}].push_back({x2,y2,c});
        }
        map<pair<int,int>,int>dp;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>q;
        q.push({0,start[0],start[1]});
        dp[{start[0],start[1]}]=0;
        while(!q.empty()){
            auto [d,i,j] = q.top();q.pop();
            cout<<i<<" "<<j<<endl;
            if(i==target[0] && j==target[1]) return d;
            if(!dp.count({i,j}) || dp[{i,j}]!=d) continue;
            for(auto e:adj[{i,j}]){
                pair<int,int>v = {e[0],e[1]};
                // cout<<v.first<<" "<<v.second<<endl;
                int w = e[2];
                if(!dp.count(v) || dp[v] > d + w){
                    dp[v]=d+w;
                    q.push({dp[v],v.first,v.second});
                }
            }
        }
        return abs(start[0]-target[0]) + abs(start[1]-target[1]);
    }
};