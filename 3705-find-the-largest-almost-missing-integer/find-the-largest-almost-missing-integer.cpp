class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        if(k==1){
            int ans=-1;
            for(auto en:mp){
                if(en.second==1){
                    ans=max(ans,en.first);
                }
            }
            return ans;
        }
        else if(k==nums.size()){
            int ans=*max_element(nums.begin(),nums.end());
            return ans;
        }
        if(mp[nums[0]]>1&&mp[nums[nums.size()-1]]>1){
            return -1;
        }
        else{
            if(mp[nums[0]]>1){
                return nums[nums.size()-1];
            }
            else if(mp[nums[nums.size()-1]]>1){
                return nums[0];
            }
        }
        int ans=max(nums[0],nums[nums.size()-1]);
        return ans;
    }
};