class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        auto count = nums.size();
        for (auto i = 1; i < count; i++) {
            if (nums[i] > count || nums[i] <= 0) continue;
            auto j = nums[i] - 1;
            auto temp = i;
            do {
                temp = nums[j] - 1;
                nums[j] = j + 1;
                j = temp;
            } while (j < count && j >= 0 && nums[j] != j + 1);
        }
        for (auto i = 0; i < count; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return count + 1;
    }
};
