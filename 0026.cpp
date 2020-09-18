class Solution {
public:
    Solution(){
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
	}
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int last=nums[0];
        vector<int>::iterator iter0 = nums.begin() + 1;
        vector<int>::iterator iter1 = nums.begin() + 1;
        for(;iter1!=nums.end();iter1++){
            if(*iter1 != last){
                *iter0 = *iter1;
                last = *iter0;
                iter0++;
            }
        }
        return iter0 - nums.begin();
    }
};
