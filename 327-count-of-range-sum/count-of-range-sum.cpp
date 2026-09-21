#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ll long long
using os = tree<pair<ll,int>,null_type,less<pair<ll,int>>,rb_tree_tag,tree_order_statistics_node_update>;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<ll>pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }
        // sort(pre.begin(),pre.end());
        os st;
        st.insert({pre[0],0});
        ll ans=0;
        for(int i=1;i<=n;i++){
           ll R = pre[i]-lower;
           ll L = pre[i]-upper;
           ll sum = st.order_of_key({R,INT_MAX})-st.order_of_key({L,-1});
           ans+=sum;
           st.insert({pre[i],i});
        }
        return (int)ans;
    }
};