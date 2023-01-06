#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
  if (grid.empty() || grid[0].empty()) return 0;
  int m = size(grid);
  int n = size(grid[0]);
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, numeric_limits<int>::max()));
  dp[1][0] = 0;

  for (int row = 1; row <= m; ++row) {
    for (int col = 1; col <= n; ++col) {
      dp[row][col] =
          grid[row - 1][col - 1] + min(dp[row - 1][col], dp[row][col - 1]);
    }
  }

  return dp[m][n];
}

int minPathSum_(vector<vector<int>>& grid) {
  if (grid.empty() || grid[0].empty()) return 0;
  int m = size(grid);
  int n = size(grid[0]);

  vector<int> dp(n);
  partial_sum(begin(grid[0]), end(grid[0]), begin(dp));

  for (int row = 1; row < m; ++row) {
    dp[0] += grid[row][0];
    for (int col = 1; col < n; ++col) {
      dp[col] = min(dp[col], dp[col - 1]) + grid[row][col];
    }
  }

  return dp[n - 1];
}

int main() {
  vector<vector<int>> grid1 = {{3, 7, 9, 2, 7},
                               {9, 8, 3, 5, 5},
                               {1, 7, 9, 8, 5},
                               {3, 8, 6, 4, 10},
                               {6, 3, 9, 7, 8}};
  vector<vector<int>> grid2 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  vector<vector<int>> grid3 = {{1, 2, 3}, {4, 5, 6}};

  assert(minPathSum_(grid1) == 49);
  assert(minPathSum_(grid2) == 7);
  assert(minPathSum_(grid3) == 12);
}
