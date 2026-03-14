#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {

            unordered_set<char> row;
            unordered_set<char> col;
            unordered_set<char> box;

            for (int j = 0; j < 9; j++) {

                if (board[i][j] != '.') {
                    if (row.count(board[i][j])) return false;
                    row.insert(board[i][j]);
                }

                if (board[j][i] != '.') {
                    if (col.count(board[j][i])) return false;
                    col.insert(board[j][i]);
                }

                int _i = 3 * (i / 3) + j / 3;
                int _j = 3 * (i % 3) + j % 3;

                if (board[_i][_j] != '.') {
                    if (box.count(board[_i][_j])) return false;
                    box.insert(board[_i][_j]);
                }
            }
        }

        return true;
    }
};

int main() {

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    cout << s.isValidSudoku(board);

    return 0;
}