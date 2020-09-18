#define LL unsigned long long
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool positive = (dividend ^ divisor) >= 0;
        LL udividend, udivisor;
        LL quotient = 0;
        LL temp = 1;
        if(dividend == INT_MIN){
            if(divisor == -1){
                return INT_MAX;
            }
            udividend = 1LL + INT_MAX;
        }else{
            udividend = abs(dividend);
        }
        if(divisor == INT_MIN){
            udivisor = 1LL + INT_MAX;
        }else{
            udivisor = abs(divisor);
        }
        if(udivisor > udividend){
            return 0;
        }
        while(udivisor <= udividend){
            udivisor <<= 1;
            temp <<= 1;
        }
        udivisor >>= 1;
        temp >>= 1;
        while(udivisor){
            udividend -= udivisor;
            quotient += temp;
            while(udivisor > udividend){
                udivisor >>= 1;
                temp >>= 1;
            }
        }
        return positive ? quotient : -quotient;
    }
};
