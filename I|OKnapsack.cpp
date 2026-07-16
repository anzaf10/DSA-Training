class Solution {
    int solve(vector<int>& val,
              vector<int>& wt,
              int N,
              int W,
              vector<vector<int>>& dp) {

        if (N == 0 || W == 0)
            return 0;

        if (dp[N][W] != -1)
            return dp[N][W];

        int include = 0;

        if (wt[N - 1] <= W) {
            include = val[N - 1] +
                      solve(val, wt, N - 1, W - wt[N - 1], dp);
        }

        int exclude = solve(val, wt, N - 1, W, dp);

        dp[N][W] = max(include, exclude);

        return dp[N][W];
    }

public:
    int knapsack(int W, vector<int>& val, vector<int>& wt) {

        int N = val.size();

        vector<vector<int>> dp(N + 1,
                               vector<int>(W + 1, -1));

        return solve(val, wt, N, W, dp);
    }
};
