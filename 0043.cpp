class Solution {
public:
    string multiply(string num1, string num2) {
        size_t l1 = num1.size(), l2 = num2.size();
        if (l1 == 1 || l2 == 1) {
            if (!(num1.compare("0") && num2.compare("0"))) {
                return string("0");
            }
        }
        size_t nth;
        constexpr size_t BUFL = 220;
        char buff[BUFL] = "";
        size_t pool[BUFL-1] = {0};
        size_t carry = 0;
        size_t temp_sum;

        for (size_t ri = 0; ri < l1; ri++) {
            for (size_t rj = 0; rj < l2; rj++) {
                pool[ri + rj] += (num1[l1-ri-1] - '0') * (num2[l2-rj-1] - '0');
            }
        }

        for (size_t ri = 0; ri < l1 + l2; ri++) {
            buff[BUFL - 2 - ri] = pool[ri] % 10 + '0';
            pool[ri+1] += pool[ri] / 10;
        }
        if (buff[BUFL - 1 - l1 - l2] == '0') {
            return string(&buff[BUFL - l1 - l2]);
        } else {
            return string(&buff[BUFL - 1 - l1 - l2]);
        }

    }
};
