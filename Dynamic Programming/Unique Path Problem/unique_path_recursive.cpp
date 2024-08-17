#include <iostream>
#include <vector>

using namespace std;

// Recursive function to calculate the number of unique paths
int uniquePaths(int m, int n) {
    // Base cases
    if (m == 1 || n == 1) {
        return 1; // There's only one path if there's only one row or column
    }

    // Recursively find the number of unique paths from the current cell
    return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}

int main() {
    int m = 3; // Number of rows
    int n = 7; // Number of columns

    int paths = uniquePaths(m, n);

    cout << "Number of unique paths in a " << m << "x" << n << " grid is: " << paths << endl;

    return 0;
}
