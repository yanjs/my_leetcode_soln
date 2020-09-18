static const int _ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t nnum=nums.size();
        vector<vector<int>>ans;
        if(nnum<=2){
            return ans;
        }
        vector<int>sol(3,0);
        size_t i,l,r,m;
        int sum=0;
        sort(nums.begin(),nums.end());
        for(i=0;i<nnum-2;i++){
            if(nums[i]>0){
                break;
            }
            if(nums[i]==nums[i+1]){
                if(nums[i]==0&&nums[i]==nums[i+2]){
                        sol[0]=0;
                        sol[1]=0;
                        sol[2]=0;
                        ans.push_back(sol);
                        break;
                }
                while(i<nnum-2&&nums[i]==nums[i+1]){
                    i++;
                }
                sum=-nums[i]*2;//[l,r]
                l=i+1;
                r=nnum-1;
                while(l<=r){
                    m=(l+r)/2;
                    if(nums[m]==sum){
                        sol[0]=nums[i];
                        sol[1]=nums[i];
                        sol[2]=nums[m];
                        ans.push_back(sol);
                        break;
                    }else if(nums[m]<sum){
                        l=m+1;
                    }else{
                        r=m-1;
                    }
                }
            }
            sum=-nums[i];
            l=i+1;
            r=nnum-1;//[l,r]
            while(l<r){
                if(nums[l]+nums[r]==sum){
                    sol[0]=nums[i];
                    sol[1]=nums[l];
                    sol[2]=nums[r];
                    ans.push_back(sol);
                }
                while(nums[l]+nums[r]==sum&&l<r){
                    l++;
                }
                while(nums[l]+nums[r]<sum&&l<r){
                    l++;
                }
                while(nums[l]+nums[r]>sum&&l<r){
                    r--;
                }
            }
        }
        return ans;
    }
};
