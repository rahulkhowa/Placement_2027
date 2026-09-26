class NumArray {
public:
    class ST{
       private:
       vector<int>tree,lazy,arr;
       int n;
       void build(int node,int l,int r){
          if(l==r){
            tree[node]=arr[l];
            return;
          }
          int mid = (l+r)/2;
          build(2*node,l,mid);
          build(2*node+1,mid+1,r);
          tree[node]=tree[2*node]+tree[2*node+1];
       }
       void apply(int node,int l,int r,int val){
         tree[node]+=(r-l+1)*val;
         lazy[node]+=val;
       }
       void push(int node,int l,int r){
         if(!lazy[node]||(l==r)) return;
         int mid = (l+r)/2;
         apply(2*node,l,mid,lazy[node]);
         apply(2*node+1,mid+1,r,lazy[node]);
         lazy[node]=0;
       }
       int query(int node,int l,int r,int ql,int qr){
          if(ql>r || qr<l){
            return 0;
          }
          if(ql<=l && qr>=r){
            return tree[node];
          }
          push(node,l,r);
          int mid = (l+r)/2;
          return query(2*node,l,mid,ql,qr)+query(2*node+1,mid+1,r,ql,qr);
       }
       void update(int node,int l,int r,int ql,int qr,int val){
         if(ql>r || qr<l){
            return;
          }
          if(ql<=l && qr>=r){
            apply(node,l,r,val);
            return;
          }
         push(node,l,r);
         int mid = (l+r)/2;
         update(2*node,l,mid,ql,qr,val);
         update(2*node+1,mid+1,r,ql,qr,val);
         tree[node] = tree[2*node]+tree[2*node+1];
       }
       public:
       ST(vector<int>&arr){
         this->arr = arr;
         this->n = arr.size();
         tree.resize(4*n);
         lazy.resize(4*n);
         build(1,0,n-1);
       }
       void rupdate(int l,int r,int val){
          return update(1,0,n-1,l,r,val);
       }
       int rquery(int l,int r){
         return query(1,0,n-1,l,r);
       }
    };

    private:
    vector<int>nums;
    ST st;

    public:
    NumArray(vector<int>& nums) : nums(nums), st(nums) {}
    
    void update(int index, int val) {
        int delta = val-nums[index];
        st.rupdate(index,index,delta);
        nums[index]=val;
    }
    
    int sumRange(int left, int right) {
        return st.rquery(left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */