class Solution {
public:
    struct Node{
        Node* child[2];
        Node(){
            child[0]=nullptr;
            child[1]=nullptr;
        }
    };
    void insert(Node* root,int x){
        Node* curr = root;
        for(int bit=31;bit>=0;bit--){
            int b = (x>>bit)&1;
            if(curr->child[b]==nullptr){
                curr->child[b] = new Node();
            }
            curr = curr->child[b];
        }
    }
    int mxor(Node* root,int x){
        Node* curr;
        int ans=0;
        for(int bit=31;bit>=0;bit--){
            int b = (x>>bit)&1;
            int want = b^1;
            if(curr->child[want]!=nullptr){
                ans|=(1<<bit);
                curr = curr->child[want];
            }
            else{
                curr = curr->child[b];
            }
        }
        return ans;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        using t = tuple<int,int,int>;
        vector<t>q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i][1],queries[i][0],i});
        }
        sort(q.begin(),q.end());
        Node* root = new Node();
        int j=0;
        vector<int>ans(q.size());
        for(auto [m,x,i]:q){
            while(j<nums.size() && nums[j]<=m){
                insert(root,nums[j]);
                j++;
            }
            if(j==0){
                ans[i]=-1;
            }
            else{
                ans[i]=mxor(root,x);
            }
        }
        return ans;
    }
};