#include <iostream>
using namespace std;

// Function to recursively calculate the number of unique BSTs
int numTrees(int n) {
    // Base case: empty tree or one node tree
    if (n == 0 || n == 1) {
        return 1;
    }
    
    int total = 0;
    
    // Calculate number of unique BSTs by considering each i as root
    for (int i = 1; i <= n; ++i) {
        total += numTrees(i - 1) * numTrees(n - i);
    }
    
    return total;
}

int main() {
    int n = 7; // Example: Compute the number of unique BSTs with 5 nodes
    cout << "Number of unique BSTs with " << n << " nodes: " << numTrees(n) << endl;
    return 0;
}
