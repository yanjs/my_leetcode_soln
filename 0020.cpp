#define MAX 5000
class Solution {
public:
    bool isValid(string s) {
        size_t i,size=s.size();
        char c;
        char buff[MAX] = {0};
        char* top = buff - 1;//]
        char* bottom = buff - 1;//(
        for(i=0;i<size;i++){
            c = s[i];
            switch(c){
                case ')':
                    if(top == bottom || *top != '('){
                        return false;
                    }
                    top--;
                    break;
                case ']':
                    if(top == bottom || *top != '['){
                        return false;
                    }
                    top--;
                    break;
                case '}':
                    if(top == bottom || *top != '{'){
                        return false;
                    }
                    top--;
                    break;
                default:
                    *++top = c;
            }
        }
        return top == bottom;
    }
};
