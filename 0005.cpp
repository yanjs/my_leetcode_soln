class Solution {
public:
    string longestPalindrome(string s) {
        //左右两开花
        int mid;
        int half=1;
        int leng;
        int i;
        char left;
        char med;
        char right;
        int jmp;
        int size=s.size();
        int sm=size-1;
        int max=1;
        int maxi=0;
        for(mid=1;mid<sm;mid+=jmp){
            jmp=1;
            left=s[mid-1];
            med=s[mid];
            right=s[mid+1];
            if(left==right){
                //形成回文核aba或aaa，进行预处理
                i=mid+2;
                while(1){
                    //防止ababababababab太慢
                    //交换下一行两个判断条件可以更快？报错？
                    if(i==size||med!=s[i]){
                        //奇数个回文
                        mid=((mid+i)>>1)-1;
                        jmp=i-mid;
                        half=jmp;
                        odd:
                        while((mid-half+1)*(size-mid-half)>0){
                            if(s[mid-half]!=s[mid+half]){
                                break;
                            }
                            half++;
                        }
                        leng=(half<<1)-1;
                        if(max<leng){
                            max=leng;
                            maxi=mid-half+1;
                        }
                        break;
                    }
                    i++;
                    if(i==size||left!=s[i]){
                        if(left==med){
                            mid=(mid+i)>>1;
                            jmp=i-mid;
                            half=jmp;
                            //重定向到偶数个
                            goto even;
                        }
                        mid=((mid+i)>>1)-1;
                        jmp=i-mid;
                        half=jmp-1;
                        //奇数个回文
                        goto odd;
                    }
                    i++;
                }
            }else if(left==med){
                //偶数个回文
                even:
                while((mid-half)*(size-mid-half)){
                    //尚未越界
                    if(s[mid+half]==s[mid-half-1]){
                        half++;
                    }else{
                        break;
                    }
                }
                leng=half<<1;
                if(max<leng){
                    max=leng;
                    maxi=mid-half;
                }
            }else if(max==1&&med==right){
                max=2;
                maxi=mid;
            }
            half=1;
        }
        if(max==1&&s[0]==s[1]){
            max=2;
        }
        return string(s,maxi,max);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int mid;
        int half=1;
        int leng;
        int i;
        char left;
        char med;
        char right;
        int jmp;
        int size=s.size();
        int sm=size-1;
        int max=1;
        int maxi=0;
        for(mid=1;mid<sm;mid+=jmp){
            jmp=1;
            left=s[mid-1];
            med=s[mid];
            right=s[mid+1];
            if(left==right){
                i=mid+2;
                while(1){
                    if(i==size||med!=s[i]){
                        mid=((mid+i)>>1)-1;
                        jmp=i-mid;
                        half=jmp;
                        odd:
                        while((mid-half+1)*(size-mid-half)>0){
                            if(s[mid-half]!=s[mid+half]){
                                break;
                            }
                            half++;
                        }
                        leng=(half<<1)-1;
                        if(max<leng){
                            max=leng;
                            maxi=mid-half+1;
                        }
                        break;
                    }
                    i++;
                    if(i==size||left!=s[i]){
                        if(left==med){
                            mid=(mid+i)>>1;
                            jmp=i-mid;
                            half=jmp;
                            goto even;
                        }
                        mid=((mid+i)>>1)-1;
                        jmp=i-mid;
                        half=jmp-1;
                        goto odd;
                    }
                    i++;
                }
            }else if(left==med){
                even:
                while((mid-half)*(size-mid-half)){
                    if(s[mid+half]==s[mid-half-1]){
                        half++;
                    }else{
                        break;
                    }
                }
                leng=half<<1;
                if(max<leng){
                    max=leng;
                    maxi=mid-half;
                }
            }else if(max==1&&med==right){
                max=2;
                maxi=mid;
            }
            half=1;
        }
        if(max==1&&s[0]==s[1]){
            max=2;
        }
        return string(s,maxi,max);
    }
};