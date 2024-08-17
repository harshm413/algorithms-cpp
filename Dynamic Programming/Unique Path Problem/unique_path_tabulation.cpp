#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the number of unique paths using dynamic programming (tabulation)
int uniquePaths(int m, int n) {
    // Create a DP array to store the number of unique paths for each cell
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the first row and first column with 1
    // There's only one way to reach any cell in the first row or first column (all the way from the start)
    for (int i = 0; i < m; ++i) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
        dp[0][j] = 1;
    }

    // Calculate the number of unique paths for each cell
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1]; // Return the number of unique paths to reach the bottom-right cell
}

int main() {
    int m = 3; // Number of rows
    int n = 7; // Number of columns

    int paths = uniquePaths(m, n);

    cout << "Number of unique paths in a " << m << "x" << n << " grid is: " << paths << endl;

    return 0;
}
