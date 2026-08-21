class Solution {
public:
    #define ll long long
    ll lcm(ll a,ll b){
        ll g = __gcd(a,b);
        return (a*b)/g; 
    }
    bool chk(ll mid,vector<int>coins,int k){
       int n = coins.size();
       ll N = 1<<n;
       ll ans=0;
       for(ll mask=1;mask<N;mask++){
           ll bit = 0,l=1;
           for(int i=0;i<n;i++){
               if(mask&(1<<i)){
                   bit++;
                   l = lcm(l,(ll)coins[i]);
               }
           }
           if(l>mid){
             continue;
           }
           if(bit&1){
             ans+=(mid/l);
           }
           else{
             ans-=(mid/l);
           }
       }
       return ans>=k;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll n = coins.size();
        sort(coins.begin(),coins.end());
        ll l=0,h=(ll)coins[0]*k;
        ll ans = (ll)coins[0]*k;
        while(l<=h){
            ll mid = l+(h-l)/2;
            if(chk(mid,coins,k)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};