class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[&](vector<int>a,vector<int>b){
            if(a[1]==b[1]){
                return a[0]<b[0];
            }
             return a[1]<b[1];
        });
        int n = courses.size();
        priority_queue<pair<int,int>>q;
        int currt = 0;
        for(int i=0;i<n;i++){
            int d = courses[i][0];
            int l = courses[i][1];
            currt+=d;
            q.push({d,l});
            if(currt>l){
               currt-=q.top().first;
               q.pop();
            }
        }
        return (int)q.size();
    }
};