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
    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        Node* root = new Node();
        for(int x:nums){
            insert(root,x);
            ans=max(ans,mxor(root,x));
        } 
        return ans;
    }
};