#include <cassert>
#include <limits>
#include <vector>

using namespace std;

int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
  int m = size(grid), n = size(grid[0]);
  vector<vector<int>> dp(m, vector<int>(n, numeric_limits<int>::max()));
  dp[0] = grid[0];

  for (int r = 1; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      for (int k = 0; k < n; ++k) {
        dp[r][k] = min(dp[r][k],
                       grid[r][k] + dp[r - 1][c] + moveCost[grid[r - 1][c]][k]);
      }
    }
  }

  return *min_element(begin(dp[m - 1]), end(dp[m - 1]));
}

int minPathCost_(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
  // TODO: implement me (only keep track of previous row)
}

int main() {
  vector<vector<int>> grid1 = {{5, 3}, {4, 0}, {2, 1}};
  vector<vector<int>> moveCost1 = {{9, 8},  {1, 5}, {10, 12},
                                   {18, 6}, {2, 4}, {14, 3}};

  vector<vector<int>> grid2 = {{5, 1, 2}, {4, 0, 3}};
  vector<vector<int>> moveCost2 = {{12, 10, 15}, {20, 23, 8}, {21, 7, 1},
                                   {8, 1, 13},   {9, 10, 25}, {5, 3, 2}};

  assert(minPathCost(grid1, moveCost1) == 17);
  assert(minPathCost(grid2, moveCost2) == 6);
}
