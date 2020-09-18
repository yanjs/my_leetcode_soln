vector<int> g_result;
vector<vector<int>> g_results;
vector<int>::const_iterator g_last;
int g_lastv;
void dfs(vector<int>::const_iterator start, int target) {
    if (target == 0) {
        g_results.push_back(g_result);
        return;
    }
    if (g_last == start) return;
    if (*start > target) return;
    int val;
    while (start != g_last && *start <= target) {
        val = *start;
        g_result.push_back(val);
        start++;
        dfs(start, target - val);
        g_result.pop_back();
        while (start != g_last && val == *start) {
            start++;
        }
    }
    return;
}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        g_results = vector<vector<int>>();
        if (candidates.empty()) return g_results;
        g_result = vector<int>();
        sort(candidates.begin(), candidates.end());
        g_last = candidates.end();
        g_lastv = *(g_last - 1);
        dfs(candidates.begin(), target);
        return g_results;
    }
};

