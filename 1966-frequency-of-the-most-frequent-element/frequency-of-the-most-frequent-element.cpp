class Solution {
public:
    long long fun(int l,int r,int ele,long long sum){
        long long ele2 = ele;
        ele2*=(r-l+1);
        return ele2-sum;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long sum=0;
        int ans=0;
        int l=0,r=0;
        while(r<n){
            sum+=nums[r];
            while(l<r && fun(l,r,nums[r],sum)>k){
                sum-=nums[l];
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};