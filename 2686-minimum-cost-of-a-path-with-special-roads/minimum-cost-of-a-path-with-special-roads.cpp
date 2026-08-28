class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int m = specialRoads.size();
        vector<pair<int,int>>pos(m+2);
        pos[0]={start[0],start[1]};
        for(int i=0;i<m;i++){
            pos[i+1]={specialRoads[i][2],specialRoads[i][3]};
        }
        pos[m+1] = {target[0],target[1]}; 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>q;
        q.push({0,0});
        vector<int>dp(m+2,INT_MAX);//nodes toh m+2 hi hai edges boht sari ho sakte hai;
        dp[0]=0;
        while(!q.empty()){
           auto [d,u] = q.top();q.pop();
           if(dp[u]!=d) continue;
           if(u==m+1) return d;
           int cost1 = abs(pos[u].first-pos[m+1].first) + abs(pos[u].second-pos[m+1].second);
           if(dp[m+1]>d+cost1){
              dp[m+1] = d+cost1;
              q.push({dp[m+1],m+1});
           }
           for(int i=0;i<m;i++){
              int cost2 = abs(pos[u].first-specialRoads[i][0]) + abs(pos[u].second-specialRoads[i][1]) + specialRoads[i][4];
              if(dp[i+1] > d+cost2){
                dp[i+1]=d+cost2;
                q.push({dp[i+1],i+1});
              }
           }
        }
        return dp[m+1];
    }
};