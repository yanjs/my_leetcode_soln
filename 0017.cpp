// Avoid using global variable
static const int _ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    int endIndex;//)
    char* two = "abc\0def\0ghi\0jkl\0mno\0pqrs\0tuv\0wxyz";
    vector<string> ans;
    char* getMap(const char& key){
        if(key > '7'){
            return two + (key - '2') * 4 + 1;
        }
        return two + (key - '2') * 4;
    }
    void getNextChar(string keys, size_t index, string sol, char c){
        sol.push_back(c);
        if(index == endIndex){
            ans.push_back(sol);
        }else{
            char* chars = getMap(keys[index]);
            while(c = *(chars++)){
                getNextChar(keys, index + 1, sol, c);//这不是尾递归，不能优化，会消耗大量栈空间
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return ans;
        }
        endIndex = digits.size();
        string sol;
        char* chars = getMap(digits[0]);
        char c;
        while(c = *(chars++)){
            getNextChar(digits, 1, sol, c);
        }
        return ans;
    }
};
