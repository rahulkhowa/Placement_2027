class Solution {
public:
    bool canCross(vector<int>& stones) {
        queue<pair<int,int>>q;
        q.push({0,0});
        set<pair<int,int>>vis;
        set<int>st(stones.begin(),stones.end());
        vis.insert({0,0});
        while(!q.empty()){
            auto [p,j] = q.front();q.pop();
            if(p==stones[stones.size()-1]) return true;
            for(int nj=j-1;nj<=j+1;nj++){
                int np = p+nj;
                if(!st.contains(np)) continue;
                if(vis.contains({np,nj})) continue;
                vis.insert({np,nj});
                q.push({np,nj});
            }
        }
        return false;
    }
};