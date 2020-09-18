/*************************************************************************
    > File Name: 0003.cpp
#include

# File Name: 0003.cpp
# Created Time: 3/27/2019 11:28:39
 ************************************************************************/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=1,max=0,seat=s.size()+1,temp;
        int pos[255]={0};
        pos[s[0]]=1;
        while(j<seat){
            if(!pos[s[j]]){
                cout<<"new char"<<s[j]<<;
                pos[s[j]]=j+1;
            }else{
                if(max<j-i){
                    max=j-i;
                }
                while(i<pos[s[j]]){
                    pos[s[i]]=0;
                    i++;
                }
            }
            j++;
        }
        return max;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
