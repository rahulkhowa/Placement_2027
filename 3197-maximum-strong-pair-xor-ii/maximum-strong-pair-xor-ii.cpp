class Solution {
public:
struct Node{
    Node* child[2];
    int cnt;

    Node(){
        child[0]=nullptr;
        child[1]=nullptr;
        cnt=0;
    }
};

void insert(Node* root,int x){
    Node* curr=root;
    curr->cnt++;

    for(int bit=31;bit>=0;bit--){
        int b=(x>>bit)&1;
        if(curr->child[b]==nullptr){
            curr->child[b]=new Node();
        }
        curr=curr->child[b];
        curr->cnt++;
    }
}

void erase(Node* root,int x){
    Node* curr=root;
    curr->cnt--;

    for(int bit=31;bit>=0;bit--){
        int b=(x>>bit)&1;
        curr=curr->child[b];
        curr->cnt--;
    }
}

int mxor(Node* root,int x){
    Node* curr=root;
    int ans=0;

    for(int bit=31;bit>=0;bit--){
        int b=(x>>bit)&1;
        int want=b^1;

        if(curr->child[want]!=nullptr && curr->child[want]->cnt>0){
            ans|=(1<<bit);
            curr=curr->child[want];
        }
        else{
            curr=curr->child[b];
        }
    }

    return ans;
}
    int maximumStrongPairXor(vector<int>& nums) {
        Node* root = new Node();
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>q;
        for(int i=0;i<n;i++){
            insert(root,nums[i]);
            q.push({nums[i],i});
            while(!q.empty() && q.top().first<((nums[i]+1)/2)){
                erase(root,q.top().first);
                q.pop();
            }
            ans=max(ans,mxor(root,nums[i]));
        }
        return ans;
    }
};