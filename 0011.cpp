static const int _ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

int max(int a,int b){
    return a<b?b:a;
}
class Solution {
public:
    int maxArea(vector<int>& height) {
        size_t totsize=height.size();
        size_t i=0,j=totsize-1;
        int maxarea=0;
        int maxl=height[0],maxr=height[totsize-1];
        while(i<j){
            if(height[i]>=height[j]){
                maxarea=max(maxarea,height[j]*(j-i));
                while(i<j&&height[j]<=maxr){
                    j--;
                }
                maxr=height[j];
            }
            if(height[i]<=height[j]){
                maxarea=max(maxarea,height[i]*(j-i));
                while(i<j&&height[i]<=maxl){
                    i++;
                }
                maxl=height[i];
            }
        }
        return maxarea;
    }
};
