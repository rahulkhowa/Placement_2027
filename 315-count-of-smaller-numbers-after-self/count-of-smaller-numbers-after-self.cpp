#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using os = tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        reverse(nums.begin(),nums.end());
        os st;
        for(int i=0;i<n;i++){
            ans[i]=st.order_of_key({nums[i],-1});
            st.insert({nums[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};