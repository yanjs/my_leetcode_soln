#include <iostream>
#include <vector>

using namespace std;
#include "0037.cpp"

int main() {
    vector<vector<char>> board = 
        {{'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};
    Solution s;
    s.solveSudoku(board);
    for (vector<vector<char>>::const_iterator i1 = board.begin(); i1 != board.end(); i1++){
        for (vector<char>::const_iterator i2 = (*i1).begin(); i2 != (*i1).end(); i2++){
            cout << *i2 << ' ';
        }
        cout << endl;
    }
    return 0;
}
