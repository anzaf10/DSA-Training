//RAT IN A MAZE//

class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& maze, int n,
               vector<string>& ans, string path,
               vector<vector<int>>& vis) {

        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        vis[i][j] = 1;

        // Down
        if (i + 1 < n && maze[i + 1][j] == 1 && !vis[i + 1][j]) {
            solve(i + 1, j, maze, n, ans, path + 'D', vis);
        }

        // Left
        if (j - 1 >= 0 && maze[i][j - 1] == 1 && !vis[i][j - 1]) {
            solve(i, j - 1, maze, n, ans, path + 'L', vis);
        }

        // Right
        if (j + 1 < n && maze[i][j + 1] == 1 && !vis[i][j + 1]) {
            solve(i, j + 1, maze, n, ans, path + 'R', vis);
        }

        // Up
        if (i - 1 >= 0 && maze[i - 1][j] == 1 && !vis[i - 1][j]) {
            solve(i - 1, j, maze, n, ans, path + 'U', vis);
        }

        vis[i][j] = 0; // Backtrack
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;

        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        solve(0, 0, maze, n, ans, "", vis);

        return ans;
    }
};
