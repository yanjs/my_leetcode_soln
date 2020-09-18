class Solution {
public:
    bool dfs(vector<vector<char>>& board, size_t x, size_t y) {
        bool invalid[9] = {false};
        char ch;
        size_t bx = x / 3 * 3, by = y / 3 * 3;
        size_t nx = x, ny = y;

        for (size_t i = 0; i < 9; i++) {
            ch = board[x][i];
            if (ch != '.') {
                invalid[ch - '1'] = true;
            }
            ch = board[i][y];
            if (ch != '.') {
                invalid[ch - '1'] = true;
            }
        }
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                ch = board[bx+i][by+j];
                if (ch != '.') {
                    invalid[ch - '1'] = true;
                }
            }
        }

        do {
            ny++;
            if (ny >= 9) {
                nx++;
                if (nx == 9) {
                    for (size_t i = 0; i < 9; i++) {
                        if (!invalid[i]) {
                            board[x][y] = i + '1';
                            return true;
                        }
                    }
                    return false;
                }
                ny = 0;
            }
        } while (board[nx][ny] != '.');

        for (size_t i = 0; i < 9; i++) {
            if (!invalid[i]) {
                board[x][y] = i + '1';
                if (dfs(board, nx, ny)) {
                    return true;
                }
            }
        }

        board[x][y] = '.';
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        size_t nx = 0, ny = 0;
        while (board[nx][ny] != '.') {
            ny++;
            if (ny >= 9) {
                nx++;
                if (nx == 9) {
                    return;
                }
                ny = 0;
            }
        }
        dfs(board, nx, ny);
    }
};
