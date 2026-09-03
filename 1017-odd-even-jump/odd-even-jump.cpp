class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        int ans=0;
        set<pair<int,int>>st;
        map<int,int>mp;
        map<int,pair<bool,bool>>dp;
        dp[n-1]={true,true};
        mp[arr[n-1]]=n-1;
        st.insert({arr[n-1],n-1});
        for(int i=n-2;i>=0;i--){
           dp[i]={false,false};
           auto it = st.lower_bound({arr[i],-1});
           if(it!=st.end()){
             pair<int,int>odd = *it;
             int ele = odd.first;
             int ind = mp[ele];
             if(dp[ind].second){
                dp[i].first = true;
             }
           }
           auto jt = st.upper_bound({arr[i],n});
           if(jt!=st.begin()){
             --jt;
             pair<int,int>even = *jt;
             int ele = even.first;
             int ind = mp[ele];
             if(dp[ind].first){
                dp[i].second = true;
             }
           }
           st.insert({arr[i],i});
           mp[arr[i]]=i;
        }
        for(int i=0;i<n;i++){
            // cout<<dp[i].first<<" "<<dp[i].second<<endl;
            if(dp[i].first){
                ans++;
            }
        }
        return ans;
    }
};