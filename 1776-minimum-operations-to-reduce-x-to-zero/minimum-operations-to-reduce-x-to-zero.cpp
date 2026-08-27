class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int ans=n+1;
        map<int,int>mp;
        int sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            if(x-sum>=0){
                mp[sum]=i;
                if(x==sum){
                    ans=min(ans,n-i);
                }
            }
        }
        int s=0;
        for(int i=0;i<n;i++){
           s+=nums[i];
           if(x>=s && mp.count(x-s)){
              ans = min(ans,i+1+n-mp[x-s]);
           }
        }
        s=0,sum=0;
        mp.clear();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(x-sum>=0){
                mp[sum]=i;
                if(x==sum){
                    ans=min(ans,i+1);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            s+=nums[i];
            if(x>=s && mp.count(x-s)){
                ans=min(ans,mp[x-s]+1+n-i);
            }
        }
        return (ans==n+1 ? -1 : ans);
    }
};