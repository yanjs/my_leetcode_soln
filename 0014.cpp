static const int _ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

size_t min(size_t a,size_t b){
    return a<b?a:b;
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t nstr=strs.size();
        if(nstr==0){
            return "";
        }
        size_t i=0,j;
        size_t minlen=strs[0].size();
        if(minlen==0){
            return "";
        }
        char lead=strs[0][0];
        for(j=1;j<nstr;j++){
            if(strs[j][0]!=lead){
                return "";
            }
            minlen=min(minlen,strs[j].size());
        }
        while(i<minlen){
            lead=strs[0][i];
            for(j=1;j<nstr;j++){
                if(strs[j][i]!=lead){
                    return string(strs[0],0,i);
                }
            }
            i++;
        }
        return string(strs[0],0,minlen);
    }
};
