#include <iostream>
#include <vector>

using namespace std;

// Helper function for recursive path counting
int uniquePathsWithObstaclesHelper(const vector<vector<int>>& obstacleGrid, int i, int j) {
    // If out of bounds or obstacle encountered, return 0
    if (i < 0 || j < 0 || obstacleGrid[i][j] == 1) {
        return 0;
    }
    // If at the start cell, return 1
    if (i == 0 && j == 0) {
        return 1;
    }
    
    // Calculate the number of unique paths from (i, j) to the start cell (0, 0)
    return uniquePathsWithObstaclesHelper(obstacleGrid, i - 1, j) + uniquePathsWithObstaclesHelper(obstacleGrid, i, j - 1);
}

// Function to calculate the number of unique paths with obstacles
int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    
    return uniquePathsWithObstaclesHelper(obstacleGrid, m - 1, n - 1);
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
