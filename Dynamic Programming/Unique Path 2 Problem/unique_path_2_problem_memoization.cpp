#include <iostream>
#include <vector>

using namespace std;

// Helper function for calculating unique paths using memoization
int uniquePathsWithObstaclesMemo(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& memo) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    
    // Base cases
    if (i >= m || j >= n || obstacleGrid[i][j] == 1) {
        return 0;
    }
    if (i == m - 1 && j == n - 1) {
        return 1; // Reached the bottom-right corner
    }
    if (memo[i][j] != -1) {
        return memo[i][j]; // Return cached result if available
    }

    // Calculate the number of unique paths from the current cell (i, j)
    int right = uniquePathsWithObstaclesMemo(obstacleGrid, i, j + 1, memo);
    int down = uniquePathsWithObstaclesMemo(obstacleGrid, i + 1, j, memo);
    
    memo[i][j] = right + down; // Store the result in the cache
    return memo[i][j];
}

// Function to calculate the number of unique paths with obstacles
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    
    vector<vector<int>> memo(m, vector<int>(n, -1)); // Initialize memoization table with -1
    return uniquePathsWithObstaclesMemo(obstacleGrid, 0, 0, memo);
}

int main() {
    // Example grid with obstacles
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int paths = uniquePathsWithObstacles(obstacleGrid);

    cout << "Number of unique paths with obstacles is: " << paths << endl;

    return 0;
}
