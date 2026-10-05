class Solution {
public:
    #define ll long long
    ll makepal(ll left,bool even){
        ll rest = left;
        if(!even){
            left = left/10;
        }
        while(left>0){
            rest = rest*10 + left%10;
            left/=10;
        }
        return rest;
    }
    string nearestPalindromic(string n) {
        int len = n.size();
        int i = len%2==0 ? len/2-1 : len/2;
        ll first = stol(n.substr(0,i+1));
        vector<ll>store;
        store.push_back(makepal(first,len%2==0));
        store.push_back(makepal(first+1,len%2==0));
        store.push_back(makepal(first-1,len%2==0));
        store.push_back((long)pow(10,len-1)-1);
        store.push_back((long)pow(10,len)+1);
        ll diff = LLONG_MAX,res=0,nl = stol(n);
        for(auto cand:store){
            if(cand==nl) continue;
            if(abs(cand-nl)<diff){
                diff = abs(cand-nl);
                res = cand;
            }
            else if(abs(cand-nl)==diff){
                res = min(res,cand);
            }
        }
        return to_string(res);
    }
};