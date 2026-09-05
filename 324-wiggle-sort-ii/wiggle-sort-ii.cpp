class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin()+n/2;
        nth_element(nums.begin(),midptr,nums.end());
        int median = *midptr;
        auto idx = [n](int i){
            return (1+(2*i))%(n|1);
        };
        int left=0;
        int i=0;
        int right=n-1;
        while(i<=right){
            int vi = idx(i);
            if(nums[vi]>median){
                swap(nums[vi],nums[idx(left)]);
                left++;
                i++;
            }
            else if(nums[vi]<median){
                swap(nums[vi],nums[idx(right)]);
                right--;
            }
            else{
                i++;
            }
        }
    }
};