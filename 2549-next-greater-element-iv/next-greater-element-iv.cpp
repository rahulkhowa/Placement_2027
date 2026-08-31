class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1),ans2(n,-1);
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            stack<pair<int,int>>backup;
            while(!st.empty() && nums[st.top().first]<nums[i]){
                if(st.top().second==2){
                    ans[st.top().first]=nums[i];
                    backup.push({st.top().first,1});
                }
                else{
                    ans2[st.top().first]=nums[i];
                }
                st.pop();
            }
            st.push({i,2});
            while(!backup.empty()){
                st.push({backup.top()});
                backup.pop();
            }
        }
        return ans2;
    }
};