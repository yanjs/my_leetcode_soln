class Solution {
public:
    Solution(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0};
        int col[9][9] = {0};
        int box[3][3][9] = {0};
        int nu;
        for(size_t i=0;i<9;i++){
            for(size_t j=0;j<9;j++){
                if((nu = board[i][j]) != '.'){
                    nu -= 49;
                    if(row[nu] > 0)return false;
                    if(col[j][nu] > 0)return false;
                    if(box[i/3][j/3][nu] > 0)return false;
                    row[nu]++;col[j][nu]++;box[i/3][j/3][nu]++;
                }
            }
            for(size_t j=0;j<9;j++){
                row[j] = 0;
            }
        }
        return true;
    }
};
