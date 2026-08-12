class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0,r=0;
        map<int,int>mp;
        int ans=0;
        while(r<n){
           mp[nums[r]]++;
           while(l<r && mp[nums[r]]>k){
               mp[nums[l]]--;
            //    if(mp[nums[l]]==0){
            //       mp.erase(nums[l]);
            //    }
               l++;
           }
           r++;
           ans=max(ans,r-l);
        }
        return ans;
    }
};