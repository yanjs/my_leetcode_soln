class Solution {
public:
    int reverse(int x) {
        long res=0;
        int dig;
        while(x){
            dig=x%10;
            res*=10;
            res+=dig;
            x/=10;
        }
        if(res<INT_MIN||res>INT_MAX){
            return 0;
        }
        return res;
    }
};
