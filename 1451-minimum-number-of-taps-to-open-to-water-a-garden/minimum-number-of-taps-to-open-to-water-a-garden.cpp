class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>mxr(n+1,0);
        for(int i=0;i<=n;i++){
            int left = max(0,i-ranges[i]);
            int right = min(n,i+ranges[i]);
            mxr[left]=max(mxr[left],right);
        }
        int currend=0,far=0,tap=0;
        for(int i=0;i<=n;i++){
            far=max(far,mxr[i]);
            if(i==currend){
                if(i>=n){
                    return tap;
                }
                if(far==currend){
                   return -1;
                }
                currend=far;
                tap++;
            }
        }
        return -1;
    }
};