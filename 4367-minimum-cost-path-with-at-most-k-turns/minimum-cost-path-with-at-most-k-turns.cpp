class Solution {
public:
    #define ll long long
    ll dp[76][76][76][4];
    int minCost(vector<vector<int>>& grid, int k) {
        for(ll i=0;i<76;i++){
            for(ll j=0;j<76;j++){
                for(ll p=0;p<76;p++){
                    for(ll d=0;d<4;d++){
                        dp[i][j][p][d]=LLONG_MAX;
                    }
                }
            }
        }
        ll n = grid.size();
        ll m = grid[0].size();
        using t = tuple<ll,ll,ll,ll,ll>;
        priority_queue<t,vector<t>,greater<>>q;
        q.push({grid[0][0],0,0,0,0});
        q.push({grid[0][0],0,0,0,1});
        q.push({grid[0][0],0,0,0,2});
        q.push({grid[0][0],0,0,0,3});
        dp[0][0][0][0]=grid[0][0];
        dp[0][0][0][1]=grid[0][0];
        dp[0][0][0][2]=grid[0][0];
        dp[0][0][0][3]=grid[0][0];
        vector<vector<ll>>dis = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto [d,i,j,turn,prv] = q.top();q.pop();
            if(i==n-1 && j==m-1) return d;
            if(d!=dp[i][j][turn][prv]) continue;
            for(ll ind=0;ind<dis.size();ind++){
                ll ni = i+dis[ind][0];
                ll nj = j+dis[ind][1];
                if(ni<0 || nj<0 || ni>=n || nj>=m) continue;
                int nturn = prv==ind?turn:turn+1;
                if(nturn>k) continue;
                int nprv = ind;
                if(dp[ni][nj][nturn][nprv]>d+grid[ni][nj]){
                    dp[ni][nj][nturn][nprv]=d+grid[ni][nj];
                    q.push({dp[ni][nj][nturn][nprv],ni,nj,nturn,nprv});
                }
            }
        }
        return -1;
    }
};