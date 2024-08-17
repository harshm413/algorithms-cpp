#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the number of unique paths with obstacles using tabulation
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    
    // Create a DP table to store the number of unique paths
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    // Initialize the starting cell
    if (obstacleGrid[0][0] == 0) {
        dp[0][0] = 1; // There's 1 way to be at the start if it's not an obstacle
    }
    
    // Fill in the first row
    for (int j = 1; j < n; ++j) {
        if (obstacleGrid[0][j] == 0) {
            dp[0][j] = dp[0][j - 1];
        } else {
            dp[0][j] = 0; // No paths if there's an obstacle
        }
    }
    
    // Fill in the first column
    for (int i = 1; i < m; ++i) {
        if (obstacleGrid[i][0] == 0) {
            dp[i][0] = dp[i - 1][0];
        } else {
            dp[i][0] = 0; // No paths if there's an obstacle
        }
    }
    
    // Fill in the rest of the DP table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            } else {
                dp[i][j] = 0; // No paths if there's an obstacle
            }
        }
    }
    
    // Return the number of unique paths to the bottom-right corner
    return dp[m - 1][n - 1];
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
