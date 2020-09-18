class Solution {
public:
    Solution(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        size_t l = 0, r = nums.size() - 1;
        if(target <= nums[0]) return 0;
        if(nums[r] < target) return r + 1;
        if(nums[r] == target) return r;
        size_t m;
        while(true){
            m = (l + r) / 2;
            if(nums[m] < target){
                l = m;
            }else if(target < nums[m]){
                r = m;
            }else{
                return m;
            }
            if(r - l <= 1){
                return r;
            }
        }
    }
};
