class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size();
        int size2=nums2.size();
        int left1=0,left2=0;
        int right1=size1-1,right2=size2-1;//[left,right]
        int mid1,mid2;
        int ins;
        int one,two,three,four;
        if(!size1){
            //只有2有数
            if(size2&1){
                //为奇数
                return nums2[(size2>>1)];
            }else{
                //为偶数
                return (nums2[size2>>1]+nums2[(size2>>1)-1])/2.0;
            }
        }
        if(!size2){
            //只有1有数
            if(size1&1){
                //为奇数
                return nums1[(size1>>1)];
            }else{
                //为偶数
                return (nums1[size1>>1]+nums1[(size1>>1)-1])/2.0;
            }
        }
        if((size1+size2)&1){
            //总个数为奇数
            if(size1-size2>0){
                //1比2多
                while(1){
                    if(size1&1){
                        //1奇，2偶√
                        mid1=(left1+right1)>>1;//1个候选
                        if(!size2){
                            return nums1[mid1];
                        }
                        mid2=(left2+right2)>>1;//2个候选
                        if(nums2[mid2]<=nums1[mid1]&&nums1[mid1]<=nums2[mid2+1]){
                            return nums1[mid1];
                        }else if(nums1[mid1]<nums2[mid2]){
                            //调整范围
                            size2>>=1;
                            left1+=size2;
                            right2-=size2;
                            size1-=size2;
                        }else{
                            size2>>=1;
                            right1-=size2;
                            left2+=size2;
                            size1-=size2;
                        }
                    }else{
                        //1偶，2奇√
                        mid2=(left2+right2)>>1;//1个候选
                        if(!size1){
                            return nums2[mid2];
                        }
                        mid1=(left1+right1)>>1;//2个候选
                        if(size2==1){
                            //冲刺
                            ins=nums2[mid2];
                            if(ins<=nums1[mid1]){
                                return nums1[mid1];
                            }else if(ins>=nums1[mid1+1]){
                                return nums1[mid1+1];
                            }else{
                                return ins;
                            }
                        }
                        if(nums1[mid1]<=nums2[mid2]&&nums2[mid2]<=nums1[mid1+1]){
                            return nums2[mid2];
                        }else if(nums1[mid1]<nums2[mid2]){
                            //调整大小
                            size2>>=1;
                            left1+=size2;
                            right2-=size2;
                            size1-=size2;
                            size2++;
                        }else{
                            size2>>=1;
                            size2++;
                            right1-=size2;
                            left2+=size2;
                            size1-=size2;
                            size2--;
                        }
                    }
                }
            }else{
                //2比1多，交换
                while(1){
                    if(size2&1){
                        mid2=(left2+right2)>>1;//1个候选
                        if(!size1){
                            return nums2[mid2];
                        }
                        mid1=(left1+right1)>>1;//2个候选
                        if(nums1[mid1]<=nums2[mid2]&&nums2[mid2]<=nums1[mid1+1]){
                            return nums2[mid2];
                        }else if(nums2[mid2]<nums1[mid1]){
                            //调整范围
                            size1>>=1;
                            left2+=size1;
                            right1-=size1;
                            size2-=size1;
                        }else{
                            size1>>=1;
                            right2-=size1;
                            left1+=size1;
                            size2-=size1;
                        }
                    }else{
                        mid1=(left1+right1)>>1;//1个候选
                        if(!size2){
                            return nums1[mid1];
                        }
                        mid2=(left2+right2)>>1;//2个候选
                        if(size1==1){
                            //冲刺
                            ins=nums1[mid1];
                            if(ins<=nums2[mid2]){
                                return nums2[mid2];
                            }else if(ins>=nums2[mid2+1]){
                                return nums2[mid2+1];
                            }else{
                                return ins;
                            }
                        }
                        if(nums2[mid2]<=nums1[mid1]&&nums1[mid1]<=nums2[mid2+1]){
                            return nums1[mid1];
                        }else if(nums2[mid2]<nums1[mid1]){
                            //调整大小
                            size1>>=1;
                            left2+=size1;
                            right1-=size1;
                            size2-=size1;
                            size1++;
                        }else{
                            size1>>=1;
                            size1++;
                            right2-=size1;
                            left1+=size1;
                            size2-=size1;
                            size1--;
                        }
                    }
                }
            }
        }else{
            //总个数为偶数
            if(size1>=size2){
                //1比2多或相等
                while(1){
                    if(size1&1){
                        //均奇
                        mid1=(left1+right1)>>1;
                        mid2=(left2+right2)>>1;
                        if(size1==1){//1 2均为1个
                            return (nums1[mid1]+nums2[mid2])/2.0;
                        }
                        if(nums1[mid1]==nums2[mid2]){
                            return nums1[mid1];
                        }
                        if(size2==1){
                            //进入冲刺阶段，2只剩1个，1还有一些
                            //极端情况
                            ins=nums2[mid2];
                            if(ins<=nums1[mid1-1]){
                                return (nums1[mid1-1]+nums1[mid1])/2.0;
                            }
                            if(ins>=nums1[mid1+1]){
                                return (nums1[mid1]+nums1[mid1+1])/2.0;
                            }
                            return (nums1[mid1]+ins)/2.0;
                        }
                        if(nums1[mid1]<nums2[mid2]){
                            size2>>=1;
                            left1+=size2;
                            right2-=size2;
                            size1-=size2;
                            size2+=1;
                        }else{
                            size2>>=1;
                            right1-=size2;
                            left2+=size2;
                            size1-=size2;
                            size2+=1;
                        }
                    }else{
                        //均偶
                        mid1=(left1+right1)>>1;//2个
                        mid2=(left2+right2)>>1;//2个
                        one=nums1[mid1];
                        two=nums1[mid1+1];
                        three=nums2[mid2];
                        four=nums2[mid2+1];
                        if(two<three){
                            size2>>=1;
                            left1+=size2;
                            right2-=size2;
                            size1-=size2;
                        }else if(four<one){
                            size2>>=1;
                            right1-=size2;
                            left2+=size2;
                            size1-=size2;
                        }else{
                            //退出
                            if(one<=three){
                                if(two<=four){
                                    return (three+two)/2.0;
                                }else{
                                    return (three+four)/2.0;
                                }
                            }else{
                                if(two<=four){
                                    return (one+two)/2.0;
                                }else{
                                    return (one+four)/2.0;
                                }
                            }
                        }
                    }
                }
            }else{
                //1比2少
                while(1){
                    if(size2&1){
                        //均奇
                        mid2=(left2+right2)>>1;
                        mid1=(left1+right1)>>1;
                        if(nums2[mid2]==nums1[mid1]){
                            return nums2[mid2];
                        }
                        if(size1==1){
                            //进入冲刺阶段，2只剩1个，1还有一些
                            //极端情况
                            ins=nums1[mid1];
                            if(ins<=nums2[mid2-1]){
                                return (nums2[mid2-1]+nums2[mid2])/2.0;
                            }
                            if(ins>=nums2[mid2+1]){
                                return (nums2[mid2]+nums2[mid2+1])/2.0;
                            }
                            return (nums2[mid2]+ins)/2.0;
                        }
                        if(nums2[mid2]<nums1[mid1]){
                            size1>>=1;
                            left2+=size1;
                            right1-=size1;
                            size2-=size1;
                            size1+=1;
                        }else{
                            size1>>=1;
                            right2-=size1;
                            left1+=size1;
                            size2-=size1;
                            size1+=1;
                        }
                    }else{
                        //均偶
                        mid2=(left2+right2)>>1;//2个
                        mid1=(left1+right1)>>1;//2个
                        one=nums2[mid2];
                        two=nums2[mid2+1];
                        three=nums1[mid1];
                        four=nums1[mid1+1];
                        if(two<three){
                            size1>>=1;
                            left2+=size1;
                            right1-=size1;
                            size2-=size1;
                        }else if(four<one){
                            size1>>=1;
                            right2-=size1;
                            left1+=size1;
                            size2-=size1;
                        }else{
                            //退出
                            if(one<=three){
                                if(two<=four){
                                    return (three+two)/2.0;
                                }else{
                                    return (three+four)/2.0;
                                }
                            }else{
                                if(two<=four){
                                    return (one+two)/2.0;
                                }else{
                                    return (one+four)/2.0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};