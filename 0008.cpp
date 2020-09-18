class Solution {
public:
    int myAtoi(string str) {
        int out;
        int idx=0;
        try{
            out=stoi(str);
        }catch(out_of_range &e){
            while(str[idx]==' '){
                idx++;
            }
            if(str[idx]=='-'){
                return INT_MIN;
            }else{
                return INT_MAX;
            }
        }catch(invalid_argument &e){
            return 0;
        }
        return out;
    }
};
