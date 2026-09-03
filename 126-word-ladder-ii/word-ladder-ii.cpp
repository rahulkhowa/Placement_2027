class Solution {
public:
    void dfs(string &e,string &b,map<string,int>&mp,vector<string>&path,vector<vector<string>>&ans){
        if(e==b){
            reverse(path.begin(),path.end());
            ans.push_back(path);
            reverse(path.begin(),path.end());
            return;
        }
        int val = mp[e];
        for(int i=0;i<e.size();i++){
            char old = e[i];
            for(char ch='a';ch<='z';ch++){
                e[i]=ch;
                if(mp.find(e)!=mp.end() && mp[e]==val-1){
                    path.push_back(e);
                    dfs(e,b,mp,path,ans);
                    path.pop_back();
                }
            }
            e[i]=old;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        set<string>st;
        for(auto it:wordList){
            st.insert(it);
        }
        if(!st.count(endWord)) return ans;
        st.erase(beginWord);
        map<string,int>mp;
        int step = 1;
        mp[beginWord] = step;
        queue<string>q;
        q.push(beginWord);
        while(!q.empty()){
            string word = q.front();q.pop();
            step = mp[word];
            for(int i=0;i<word.size();i++){
                char old = word[i];
                for(char c='a';c<='z';c++){
                    if(c==old) continue;
                    word[i]=c;
                    if(st.count(word)){
                        mp[word]=step+1;
                        q.push(word);
                        st.erase(word);
                    }
                }
                word[i]=old;
            }
        }
        if(!mp.count(endWord)) return ans;
        vector<string>path={endWord};
        dfs(endWord,beginWord,mp,path,ans);
        return ans;
    }
};