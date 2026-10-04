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
    void dfs(int u,vector<vector<int>>&graph,vector<vector<pair<int,int>>>&store,Node* root,vector<int>&ans){
        insert(root,u);
        for(auto [val,i]:store[u]){
           ans[i]=mxor(root,val);
        }
        for(int v:graph[u]){
            dfs(v,graph,store,root,ans);
        }
        erase(root,u);
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();
        int r = -1;
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++){
            if(parents[i]==-1){
                r=i;
            }
            else{
                graph[parents[i]].push_back(i);
            }
        }
        vector<vector<pair<int,int>>>store(n);
        for(int i=0;i<queries.size();i++){
            int node = queries[i][0];
            int val =  queries[i][1];
            store[node].push_back({val,i});
        }
        Node* root = new Node();
        vector<int>ans(queries.size());
        dfs(r,graph,store,root,ans);
        return ans;
    }
};