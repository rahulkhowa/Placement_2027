#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using os = tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>;
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+(nums[i]==target?1:-1);
        }
        os st;
        st.insert({pre[0],0});
        int ans=0;
        for(int i=1;i<=n;i++){
           ans+=(st.order_of_key({pre[i],-1}));
           st.insert({pre[i],i});
        }
        return ans;
    }
};