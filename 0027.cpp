class Solution {
public:
    Solution(){
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
	}
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0){
            return 0;
        }
        vector<int>::iterator iter0 = nums.begin();
        vector<int>::iterator iter1 = nums.begin();
        for(;iter1!=nums.end();iter1++){
            if(*iter1 != val){
                *iter0 = *iter1;
                iter0++;
            }
        }
        return iter0 - nums.begin();
    }
};
