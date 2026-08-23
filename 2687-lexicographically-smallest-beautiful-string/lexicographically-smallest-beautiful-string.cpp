class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        string ans = "";
        int n = s.size();
        int ind = -1;
        for(int i=n-1;i>=0;i--){
            for(char c=s[i]+1;c<'a'+k;c++){
               if(i-1>=0 && c==s[i-1]) continue;
               if(i-2>=0 && c==s[i-2]) continue;
               s[i]=c;
               ind=i;
               break;
            }
            if(ind!=-1){
                break;
            }
        }
        cout<<ind;
        if(ind==-1){
            return ans;
        }
        for (int i = ind + 1; i < n; i++) {
            for (char c = 'a'; c < 'a' + k; c++) {
                if (c == s[i - 1])
                    continue;
                if (i - 2 >= 0 && c == s[i - 2])
                    continue;
                if (i - 1 >= 0 && c == s[i - 1])
                    continue;
                s[i] = c;
                break;
            }
        }
        return s;
    }
};