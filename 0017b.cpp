class Link{
    Link* next;
    char val;
    char zero;//[
    char carry;//)
    char* buffpos;
public:
    Link(char digit, Link* next, char* pos): buffpos(pos){
        this->next = next;
        if(digit < '7'){
            zero = (digit - '2') * 3 + 'a';
            carry = zero + 3;
        }else if(digit == '7'){
            zero = (digit - '2') * 3 + 'a';
            carry = zero + 4;
        }else if(digit == '8'){
            zero = (digit - '2') * 3 + 'b';
            carry = zero + 3;
        }else{
            zero = (digit - '2') * 3 + 'b';
            carry = zero + 4;
        }
        val = zero;
        *buffpos = val;
    }
    bool inc(){//return false to stop
        val++;
        if(val < carry){
            *buffpos = val;
            return true;
        }
        if(!next){
            return false;
        }else{
            val = zero;
            *buffpos = val;
            return next->inc();
        }
    }
};
class Solution {
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        int i;
        int len = digits.size();
        Link* curr = NULL;
        string sol;
        char buff[20] = {0};
        if(len){
            for(i=0;i<len;i++){
                curr = new Link(digits[i], curr, buff + i);
            }
            ans.push_back(string(buff));
            while(curr->inc()){
                ans.push_back(string(buff));
            }
        }
        return ans;
    }
};
