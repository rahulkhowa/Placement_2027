class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int,int>>ind(26,{INT_MAX,INT_MIN});
        for(int i=0;i<s.size();i++){
            int c = s[i]-'a';
            ind[c].first = min(ind[c].first,i);
            ind[c].second = i;
        }
        vector<pair<int,int>>interval;
        for(int i=0;i<=25;i++){
            if(ind[i].first==INT_MAX) continue;
            int l = ind[i].first;
            int r = ind[i].second;
            int flg=0;
            for(int j=l;j<=r;j++){
                int c = s[j]-'a';
                if(ind[c].first<l){
                    flg=1;
                    break;
                }
                r=max(r,ind[c].second);
            }
            if(!flg){
                interval.push_back({r,l});
            }
        }
        sort(interval.begin(),interval.end());
        int prev = -1;
        vector<string>ans;
        for(auto [r,l]:interval){
            if(l>prev){
                ans.push_back(s.substr(l,r-l+1));
                prev=r;
            }
        }
        return ans;
    }
};