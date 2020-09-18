class Solution {
public:
    Solution(){
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
	}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        if(nums.size() < 1)return result;
        size_t l = 0, r = nums.size() - 1, m; // (l,r)
        size_t lm;
        if(target < nums[0] || target > nums[r]){
            return result;
        }
        if(target == nums[0]){
            result[0] = 0;
            if(target == nums[r]){
                result[1] = r;
                return result;
            }
            while(true){
                m = (l + r) / 2;
                if(target == nums[m]){
                    l = m;
                }else{
                    r = m;
                }
                if(r - l <= 1){
                    result[1] = l;
                    return result;
                }
            }
        }
        if(target == nums[r]){
            result[1] = r;
            while(true){
                m = (l + r) / 2;
                if(target == nums[m]){
                    r = m;
                }else{
                    l = m;
                }
                if(r - l <= 1){
                    result[0] = r;
                    return result;
                }
            }
        }
        while(true){
            m = (l + r) / 2;
            if(nums[m] > target){
                r = m;
            }else if(nums[m] < target){
                l = m;
                if (r - l <= 1){
                    return result;
                }
            }else{
                //l
                while(true){
                    lm = (l + m) / 2;
                    if(nums[lm] < target){
                        l = lm;
                    }else{
                        m = lm;
                    }
                    if(m - l <= 1){
                        result[0] = m;
                        break;
                    }
                }
                //r
                while(true){
                    lm = (m + r) / 2;
                    if(nums[lm] > target){
                        r = lm;
                    }else{
                        m = lm;
                    }
                    if(r - m <= 1){
                        result[1] = m;
                        return result;
                    }
                }
            }
        }
    }
};
