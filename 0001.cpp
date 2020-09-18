class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums2(nums);
        vector<int> r;
        int i=0,j=nums.size()-1,k;
        std::sort(nums.begin(),nums.end());
        while(i<j){
            if(nums[i]+nums[j]==target){
                break;
            }
            nums[i]+nums[j]<target?i++:j--;
        }
        for(k=0;k<nums2.size();k++){
            if(nums2[k]==nums[i]||nums2[k]==nums[j]){
                r.push_back(k);
                if(r.size()==2){
                    return r;
                }
            }
        }
        return vector<int>();
    }
};
