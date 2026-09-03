class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        int N = 1<<n;
        int ans=0;
        vector<int>fre(26,0);
        for(char c:letters){
            fre[c-'a']++;
        }
        for(int mask=0;mask<N;mask++){
            int s=0;
            vector<int>fre1(26,0);
            for(int i=0;i<n;i++){
               if(mask&(1<<i)){
                 for(int j=0;j<words[i].size();j++){
                    char c = words[i][j];
                    fre1[c-'a']++;
                 }
               }
            }
            int flg=0;
            for(int i=0;i<26;i++){
                if(fre1[i]>fre[i]){
                    flg=1;
                }
                s+=(fre1[i]*score[i]);
            }
            if(!flg){
                ans=max(ans,s);
            }
        }
        return ans;
    }
};