class Solution {
public:	
    Solution(){
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
	}
    int longestValidParentheses(string s) {
        size_t size = s.size();
        if(size < 2){
            return 0;
        }
        int cp = 0;
        int maxl = 0;
        int maymaxl;
        int mincp = 0;
        int cplist[size+1] = {0};
        size_t mincpi = 0;
        size_t i;
        for(i=0;i<size;++i){
            switch(s[i]){
                case '(':
                    ++cp;
                    break;
                case ')':
                    --cp;
                    if(cp == mincp){
                        maymaxl = i + 1 - mincpi;
                        maxl = maxl<maymaxl ? maymaxl : maxl;
                    }
                    if(cp < mincp){
                        mincp = cp;
                        mincpi = i + 1;
                    }
                    break;
            }
            cplist[i+1] = cp;
        }
        //rev
        mincp = cp;
        mincpi = size;
        for(i=size-1;i<size;--i){
            if(cplist[i] == mincp){
                maymaxl = mincpi - i;
                maxl = maxl<maymaxl ? maymaxl : maxl;
            }
            if(cplist[i] < mincp){
                mincp = cplist[i];
                mincpi = i;
            }
        }
        return maxl;
    }
};
