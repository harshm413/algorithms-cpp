#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// Helper function to calculate the minimum path sum using memoization
int minPathSumMemo(const vector<vector<int>>& grid, int i, int j, vector<vector<int>>& memo) {
    // Base case: if we are at the top-left corner
    if (i == 0 && j == 0) {
        return grid[i][j];
    }

    // Check if the result is already computed and cached
    if (i < 0 || j < 0) {
        return INT_MAX; // Out of bounds
    }
    if (memo[i][j] != -1) {
        return memo[i][j]; // Return cached result
    }

    // Calculate minimum path sum from top and left cells
    int fromTop = minPathSumMemo(grid, i - 1, j, memo);
    int fromLeft = minPathSumMemo(grid, i, j - 1, memo);
    
    // Store the result in the cache and return it
    memo[i][j] = grid[i][j] + min(fromTop, fromLeft);
    return memo[i][j];
}

int minPathSum(const vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    // Initialize memoization table with -1
    vector<vector<int>> memo(m, vector<int>(n, -1));

    // Call the helper function starting from the bottom-right corner
    return minPathSumMemo(grid, m - 1, n - 1, memo);
}

int main() {
    // Example grid
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int minSum = minPathSum(grid);

    cout << "Minimum path sum is: " << minSum << endl;

    return 0;
}
