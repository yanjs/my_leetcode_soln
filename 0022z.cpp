//https://leetcode.com/submissions/api/detail/22/cpp/4/
class Solution {
    template<uint8_t count>
    __attribute__((always_inline)) static void go(vector<string>& result, string str, int depth, int pos) noexcept {
        while (true) {
            if (depth + pos == str.size()) {
                result.emplace_back(move(str));
                return;
            }
            if constexpr (count > 0) if (depth) go<count - 1>(result, str, depth - 1, pos + 1);
            str[pos++] = '(';
            ++depth;
        }
    }

public:
    static vector<string> generateParenthesis(int n) noexcept {
        size_t catalan = 1;
        for (size_t i = 1; i < n; ++i) catalan = catalan * (4 * i + 2) / (i + 2);

        vector<string> result;
        result.reserve(catalan);

        go<10>(result, string(2 * n, ')'), 0, 0);
        return result;
    }
};

static const auto _ = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }(); 
