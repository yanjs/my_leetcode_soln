class Solution {
public:/*
	Solution(){
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
	}*/
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
            return;
        }
        vector<int>::iterator iter = nums.end() - 1;
        vector<int>::iterator liter, riter = iter, miter;
        int last = *iter;
        while(iter != nums.begin()){
            --iter;
            if(*iter < last){
                liter = iter + 1;
                last = *iter;
                goto ex;
            }
            last = *iter;
        }
        sort(iter, nums.end());
        return;
        ex:
#define USE_DICHTOMY 1
#if USE_DICHTOMY
        while(*riter <= last){
            miter = liter + (riter - liter) / 2;
            if(*miter <= last){
                riter = miter - 1;
            }else if(*miter > last){
                liter = miter;
            }
            if(*riter <= last){
                --riter;
            }
        }
#else
        while(*riter <= last){
            riter--;
        }
#endif
        swap(*iter, *riter);
        sort(iter + 1, nums.end());
    }
};

