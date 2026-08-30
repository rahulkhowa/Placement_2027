class Solution {
public:
    long long maximumValueSum(vector<int>& nums,int k,vector<vector<int>>& edges){
        int n=nums.size();
        vector<int>store;

        for(int i=0;i<n;i++){
            store.push_back(k-2*(nums[i]&k));
        }

        sort(store.rbegin(),store.rend());

        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        long long ans=sum;

        for(int i=0;i+1<n;i+=2){
            sum+=store[i]+store[i+1];
            ans=max(ans,sum);
        }

        return ans;
    }
};