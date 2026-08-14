class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[&](vector<int>a,vector<int>b){
              if(a[0]==b[0]){
                return a[1]>b[1];
              }
              return a[0]<b[0];
        });
        vector<int>tail;
        for(auto e:envelopes){
            int v = e[1];
            auto it = lower_bound(tail.begin(),tail.end(),v);
            if(it==tail.end()){
                tail.push_back(v);
            }
            else{
                *it=v;
            }
        }
        return tail.size();
    }
};