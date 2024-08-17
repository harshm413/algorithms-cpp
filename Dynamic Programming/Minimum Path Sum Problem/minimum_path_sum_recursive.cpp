#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// Helper function to calculate the minimum path sum recursively
int minPathSumRecursive(const vector<vector<int>>& grid, int i, int j) {
    // Base case: if we are at the top-left corner
    if (i == 0 && j == 0) {
        return grid[i][j];
    }
    
    // If we are outside the grid boundaries
    if (i < 0 || j < 0) {
        return INT_MAX; // Return a large number to ignore invalid paths
    }
    
    // Recursive calls to explore the paths: down and right
    int fromTop = minPathSumRecursive(grid, i - 1, j);
    int fromLeft = minPathSumRecursive(grid, i, j - 1);
    
    // Calculate the minimum path sum to reach the current cell
    return grid[i][j] + min(fromTop, fromLeft);
}

int minPathSum(const vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    // Call the recursive function starting from the bottom-right corner
    return minPathSumRecursive(grid, m - 1, n - 1);
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
