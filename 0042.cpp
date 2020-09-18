class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }
        vector<int>::const_iterator li = height.begin(), ri = height.end() - 1;
        int lm = *li, rm = *ri;
        int tot = 0;

        while (li < ri) {
            if (lm < rm) {
                while (li < ri) {
                    li++;
                    if (*li <= lm) {
                        tot += lm - *li;
                    } else {
                        lm = *li;
                        break;
                    }
                }
            } else {
                while (li < ri) {
                    ri--;
                    if (*ri <= rm) {
                        tot += rm - *ri;
                    } else {
                        rm = *ri;
                        break;
                    }
                }
            }
        }
        return tot;
    }
};
