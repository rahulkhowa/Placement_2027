class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),[](auto &a,auto &b){
            return a[2]<b[2];
        });
        vector<bool>know(n,false);
        know[0]=know[firstPerson]=true;
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        int timer=1;
        for(int i=0;i<(int)meetings.size();){
            int j=i;
            int t=meetings[i][2];
            vector<int>people;
            while(j<(int)meetings.size() && meetings[j][2]==t){
                int u=meetings[j][0];
                int v=meetings[j][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
                people.push_back(u);
                people.push_back(v);
                j++;
            }
            queue<int>q;
            for(int u:people){
                if(know[u] && vis[u]!=timer){
                    vis[u]=timer;
                    q.push(u);
                }
            }
            while(!q.empty()){
                int u=q.front();
                q.pop();
                know[u]=true;
                for(int v:adj[u]){
                    if(vis[v]!=timer){
                        vis[v]=timer;
                        q.push(v);
                    }
                }
            }
            for(int u:people){
                adj[u].clear();
            }
            timer++;
            i=j;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(know[i])
                ans.push_back(i);
        }
        return ans;
    }
};