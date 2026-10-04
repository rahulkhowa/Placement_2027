class Solution {
public:
    #define ll long long
    ll MOD = 1e9+7;
    ll modpow(ll a,ll b){
        ll res = 1;
        while(b){
            if(b%2==1){
                res = (res * a)%MOD;
            }
            a = (a * a)%MOD;
            b>>=1;
        }
        return res;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier==1) return nums;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>q;
        int n = nums.size();
        for(int i=0;i<n;i++){
            q.push({nums[i],i});
        }
        unordered_map<int,int>m,m1;
        while(1){
            if((int)m1.size()==n||k==0) break;
            ll x = q.top().first;
            ll ind =  q.top().second;
            q.pop();
            x*=multiplier;
            q.push({x,ind});
            m1[ind]++;k--;
        }
        vector<ll>v(n);
        while(!q.empty()){
            ll x = q.top().first;
            ll ind = q.top().second;
            v[ind]=x;
            q.pop();
        }
        for(int i=0;i<n;i++){
            q.push({v[i],i});
        }
        int rep = k/n;
        int md = k%n;
        while(!q.empty()){
            int x = q.top().second;
            q.pop();
            m[x]=rep;
            if(md>0){
                m[x]++;
                md--;
            }
        }
        for(int i=0;i<n;i++){
            ll mlt = modpow(multiplier,m[i]);
            v[i] = ((v[i]%MOD)*(mlt%MOD))%MOD;
            nums[i]=v[i];
        }
        return nums;
    }
};