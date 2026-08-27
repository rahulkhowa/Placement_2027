class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        //relation with consecutive {i,i+1} -> x^1
        unordered_map<int,int>pos;
        int n = row.size();
        int ans=0;
        for(int i=0;i<n;i++){
           pos[row[i]]=i;
        }
        for(int i=0;i<n;i+=2){
            int curr = row[i];
            int ext = curr^1;
            if(ext!=row[i+1]){
                ans++;
                int thr = pos[ext];
                int store = row[i+1];
                swap(row[i+1],row[thr]);
                pos[ext]=i+1;
                pos[store]=thr;
            }
        }
        return ans;
    }
};