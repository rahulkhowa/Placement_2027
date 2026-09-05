class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>>a;
        for(int i=0;i<n;i++){
            a.push_back({capital[i],profits[i]});
        }
        sort(a.begin(),a.end());
        priority_queue<int>q;
        q.push(0);
        int ans=w;
        int i=0;
        while(k--){
            while(i<n && w>=a[i].first){
                q.push(a[i].second);
                i++;
            }
            if(!q.empty()){
                auto mxp = q.top();q.pop();
                w+=mxp;
            }
        }
        return w;
    }
};