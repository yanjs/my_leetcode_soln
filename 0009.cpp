class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0){return true;}
        if(x<0||x%10==0){return false;}
        int x1=0;
        while(x>x1){
            x1*=10;
            x1+=x%10;
            x/=10;
        }
        return x==x1||x==x1/10;
    }
};
