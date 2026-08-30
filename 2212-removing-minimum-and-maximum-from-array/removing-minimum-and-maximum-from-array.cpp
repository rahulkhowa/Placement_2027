class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn=INT_MAX,mx=INT_MIN;
        int ind1=-1,ind2=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>mx){
                mx=nums[i];
                ind2=i;
            }
            if(nums[i]<mn){
                mn=nums[i];
                ind1=i;
            }
        }
        if(ind1>ind2) swap(ind1,ind2);
        return min({(ind2+1),(n-ind1),(ind1+1+n-ind2)});
    }
};