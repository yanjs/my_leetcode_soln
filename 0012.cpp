static const int _ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

string roman[4][10]={
    {"","I","II","III","IV","V","VI","VII","VIII","IX"},
    {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
    {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
    {"","M","MM","MMM"},
};
class Solution {
public:
    string intToRoman(int num) {
        string out="";
        int i=0;
        int dig;
        while(num){
            dig=num%10;
            num/=10;
            out=roman[i++][dig]+out;
        }
        return out;
    }
};
