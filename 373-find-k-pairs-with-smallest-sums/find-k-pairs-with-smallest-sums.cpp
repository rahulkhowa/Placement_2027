class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        using t = tuple<int,int,int>;
        priority_queue<t,vector<t>,greater<>>q;
        set<pair<int,int>>vis;
        q.push({nums1[0]+nums2[0],0,0});
        vis.insert({0,0});
        vector<vector<int>>ans;
        while(k-- && !q.empty()){
            auto [s,i,j] = q.top();
            q.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(i+1<n && !vis.count({i+1,j})){
                q.push({nums1[i+1]+nums2[j],i+1,j});
                vis.insert({i+1,j});
            }
            if(j+1<m && !vis.count({i,j+1})){
                q.push({nums1[i]+nums2[j+1],i,j+1});
                vis.insert({i,j+1});
            }
        }
        return ans;
    }
};