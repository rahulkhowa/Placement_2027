class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=0;
        long long sum=0;
        int ans = 1;
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        for(auto e:mp){
            ans=max(ans,e.second);
        }
        while(r<n){
            sum+=(nums[r]-nums[(l+r)/2]);
            while(l<r && sum>k){
               sum-=(nums[(l+r+1)/2]-nums[l]);
               l++;
            } 
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};