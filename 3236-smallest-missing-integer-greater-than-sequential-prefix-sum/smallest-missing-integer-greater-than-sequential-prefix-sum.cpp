class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        int sum=0;
        int prev=nums[0]-1;
        for(int i=0;i<n;i++){
            if(nums[i]==prev+1){
                ans++;
                sum+=nums[i];
                prev=nums[i];
            }
            else{
                break;
            }
        }
        sort(nums.begin(),nums.end());
        for(int x:nums){
            if(x==sum){
               sum++;
            }
        }
        return sum;
    }
};