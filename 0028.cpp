//KMP算法，但是似乎不是很快
/class Solution {
public:
    Solution(){
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
	}
    int strStr(string haystack, string needle) {
        size_t nsize = needle.size();
        if(nsize == 0){
            return 0;
        }
        int next[nsize] = {-1};
        size_t i = 0, j;
        for(j=2;j<nsize;){
            if(i == -1 || needle[i] == needle[j - 1]){
                ++i;
                next[j] = i;
                ++j;
            }else{
                i = next[i];
            }
        }
        size_t size = haystack.size();
        for(i=0,j=0;i<size;){
            if(haystack[i] == needle[j]){
                ++j;
                if(j == nsize){
                    return i - j + 1;
                }
                ++i;
            }else{
                if(j == 0){
                    ++i;
                }else{
                    j = next[j];
                }
            }
        }
        return -1;
    }
};/
