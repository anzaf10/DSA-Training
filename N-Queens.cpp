//leetcode---51//


class Solution {
public:

    bool isSafe(int row, int col, vector<string>& board, int n) {

        // Check column
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check left diagonal
        int i = row - 1;
        int j = col - 1;

        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        // Check right diagonal
        i = row - 1;
        j = col + 1;

        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }

        return true;
    }

    void solve(int row, int n, vector<string>& board,
               vector<vector<string>>& ans) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(row, col, board, n)) {

                board[row][col] = 'Q';

                solve(row + 1, n, board, ans);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solve(0, n, board, ans);

        return ans;
    }
};
