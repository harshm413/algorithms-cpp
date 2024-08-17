#include <iostream>
#include <vector>

using namespace std;

// Helper function to calculate the number of unique paths using memoization
int uniquePathsMemo(int m, int n, vector<vector<int>>& memo) {
    // Base cases
    if (m == 1 || n == 1) {
        return 1; // There's only one path if there's only one row or column
    }
    
    if (memo[m][n] != -1) {
        return memo[m][n]; // Return cached result if available
    }

    // Calculate the number of unique paths recursively
    memo[m][n] = uniquePathsMemo(m - 1, n, memo) + uniquePathsMemo(m, n - 1, memo);
    
    return memo[m][n];
}

int uniquePaths(int m, int n) {
    // Initialize memoization array with -1
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    return uniquePathsMemo(m, n, memo);
}

int main() {
    int m = 3; // Number of rows
    int n = 7; // Number of columns

    int paths = uniquePaths(m, n);

    cout << "Number of unique paths in a " << m << "x" << n << " grid is: " << paths << endl;

    return 0;
}
