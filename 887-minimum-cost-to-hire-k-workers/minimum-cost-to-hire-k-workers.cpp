class Solution {
public:
    #define d double
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<d,int>>rat;
        for(int i=0;i<n;i++){
            rat.push_back({static_cast<d>(wage[i]) / quality[i], quality[i]});
        }
        sort(rat.begin(),rat.end());
        priority_queue<int>w;
        d ct = 0;
        d total_cost = numeric_limits<double>::max();
        for(int i=0;i<n;i++){
            w.push(rat[i].second);
            ct+=rat[i].second;
            if(w.size()>k){
                ct-=w.top();
                w.pop();
            }
            if(w.size()==k){
               total_cost = min(total_cost,ct*rat[i].first);
            }
        }
        return total_cost;
    }
};