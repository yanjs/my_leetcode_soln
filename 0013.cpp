static const int _ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    int romanToInt(string s) {
        size_t i=0;
        int ans=0;
        if(s[i]=='M'){
            ans+=1000;
            i++;
            if(s[i]=='M'){
                ans+=1000;
                i++;
                if(s[i]=='M'){
                    ans+=1000;
                    i++;
                }
            }
        }
        if(s[i]=='D'){
            ans+=500;
            i++;
            if(s[i]=='C'){
                ans+=100;
                i++;
                if(s[i]=='C'){
                    ans+=100;
                    i++;
                    if(s[i]=='C'){
                        ans+=100;
                        i++;
                    }
                }
            }
        }else if(s[i]=='C'){
            ans+=100;
            i++;
            if(s[i]=='M'){
                ans+=800;
                i++;
            }else if(s[i]=='D'){
                ans+=300;
                i++;
            }else if(s[i]=='C'){
                ans+=100;
                i++;
                if(s[i]=='C'){
                    ans+=100;
                    i++;
                }
            }
        }
        if(s[i]=='L'){
            ans+=50;
            i++;
            if(s[i]=='X'){
                ans+=10;
                i++;
                if(s[i]=='X'){
                    ans+=10;
                    i++;
                    if(s[i]=='X'){
                        ans+=10;
                        i++;
                    }
                }
            }
        }else if(s[i]=='X'){
            ans+=10;
            i++;
            if(s[i]=='C'){
                ans+=80;
                i++;
            }else if(s[i]=='L'){
                ans+=30;
                i++;
            }else if(s[i]=='X'){
                ans+=10;
                i++;
                if(s[i]=='X'){
                    ans+=10;
                    i++;
                }
            }
        }
        if(s[i]=='V'){
            ans+=5;
            i++;
            if(s[i]=='I'){
                ans+=1;
                i++;
                if(s[i]=='I'){
                    ans+=1;
                    i++;
                    if(s[i]=='I'){
                        ans+=1;
                        i++;
                    }
                }
            }
        }else if(s[i]=='I'){
            ans+=1;
            i++;
            if(s[i]=='X'){
                ans+=8;
                i++;
            }else if(s[i]=='V'){
                ans+=3;
                i++;
            }else if(s[i]=='I'){
                ans+=1;
                i++;
                if(s[i]=='I'){
                    ans+=1;
                    i++;
                }
            }
        }
        return ans;
    }
};
