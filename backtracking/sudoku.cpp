#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<vector<int> > MeraSudoku;
    bool checkSudoku(int& row, int& col)
    {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (MeraSudoku[i][j] == 0) {
                    row = i;
                    col = j;
                    return false;
                }
            }
        }
        return true;
    }

    bool inCol(int j, int num)
    {
        for (int i = 0; i < 9; i++) {
            if (MeraSudoku[i][j] == num)
                return false;
        }
        return true;
    }
    bool inSmall(int row, int col, int num)
    {
        int rowfactor = row - (row % 3);
        int colfactor = col - (col % 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int item = MeraSudoku[i + rowfactor][j + colfactor];
                if (item == num)
                    return false;
            }
        }
        return true;
    }
    bool inRow(int i, int num)
    {
        for (int j = 0; j < 9; j++) {
            if (MeraSudoku[i][j] == num)
                return false;
        }
        return true;
    }
    bool isPossibleToPut(int row, int col, int number)
    {
        bool r = inRow(row, number);//same row
        bool c = inCol(col, number);//same column
        bool s = inSmall(row, col, number);//same small square
        return r && c && s;
    }
    bool solve(vector<vector<int> >& MeraSudoku)
    {
        int row = 0;
        int col = 0;
        if (checkSudoku(row, col)) {//check if sudoku is filled
            return true;
        }
        for (int number = 1; number <= 9; number++) {
            if (isPossibleToPut(row, col, number)) {//check the filling criteria
                MeraSudoku[row][col] = number;
                if (solve(MeraSudoku))//recursive call
                    return true;
                MeraSudoku[row][col] = 0;//backtraking
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char> >& board)
    {
        MeraSudoku.resize(9, vector<int>(9, 0));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    MeraSudoku[i][j] = (board[i][j] - '0');
                }
            }
        }
        solve(MeraSudoku);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = MeraSudoku[i][j] + '0';
                board[i][j] = ch;
            }
        }
        return;
    }
};
