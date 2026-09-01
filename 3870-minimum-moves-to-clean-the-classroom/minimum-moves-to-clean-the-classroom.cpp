class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int cnt = 0;
        int si=-1,sj=-1;
        vector<pair<int,int>>lt;
        map<pair<int,int>,int>lt_mask;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(classroom[i][j] == 'S'){
                     si=i;
                     sj=j;
                }
                else if(classroom[i][j]=='L'){
                    lt_mask[{i,j}]=cnt;
                    lt.push_back({i,j});
                    cnt++;
                }
            }
        }
        if(cnt==0){
            return 0;
        }
        int target = (1 << cnt) - 1;

        vector<vector<vector<vector<int>>>>dist(n,vector<vector<vector<int>>>(m,vector<vector<int>>(energy+1,vector<int>(target+1,-1))));
        dist[si][sj][energy][0]=0;
        queue<tuple<int,int,int,int>>q;
        q.push({si,sj,energy,0});


        while(!q.empty()){
            auto [i,j,e,mask] = q.front();
            q.pop();
           
            int move = dist[i][j][e][mask];

            if(mask == target) return move;
            for(auto& d : dir){
                int ni = i + d.first;
                int nj = j + d.second;
                if(ni < 0 || nj < 0 || ni >= n || nj >= m || e<=0) continue;
                char cell = classroom[ni][nj];
                if(cell == 'X') continue;
                int ne = e - 1;
                int nmove = move+1;
                int nmask=mask;

                if(cell=='L'){
                    int lcnt = lt_mask.at({ni,nj});
                    nmask|=(1<<lcnt);
                }

                if(cell=='R'){
                    ne = energy;
                }

                if(dist[ni][nj][ne][nmask]==-1||nmove<dist[ni][nj][ne][nmask]){
                    dist[ni][nj][ne][nmask] = nmove;
                    q.push({ni,nj,ne,nmask});
                }
                
            }
        }

        return -1;
    }
};