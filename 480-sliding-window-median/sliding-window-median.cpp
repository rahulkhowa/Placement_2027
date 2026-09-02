#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using os = tree<pair<double,int>,null_type,less<pair<double,int>>,rb_tree_tag,tree_order_statistics_node_update>;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>ans;
        os st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            double ele = nums[i];
            st.insert({ele,i});
            if(i-k>=0){
                double pele = nums[i-k];
                st.erase({pele,i-k});
            }
            if(i>=k-1){
                if(k%2==0){
                   int id1 = (k-1)/2;
                   int id2 = k/2;
                   pair<double,int>m1 = *st.find_by_order(id1);
                   pair<double,int>m2 = *st.find_by_order(id2);
                   double two = 2;
                   double to_put = (m1.first+m2.first)/two;
                   ans.push_back(to_put);
                }
                else{
                   int id2 = k/2;
                   pair<double,int>m2 = *st.find_by_order(id2);
                   double two = 2;
                   double to_put = (m2.first);
                   ans.push_back(to_put);
                }
            }
        }
        return ans;
    }
};