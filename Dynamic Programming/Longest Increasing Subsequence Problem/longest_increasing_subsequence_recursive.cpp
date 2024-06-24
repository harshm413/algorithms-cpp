#include <iostream>
#include <vector>
#include <algorithm> // For max function

using namespace std;

// Recursive function to find the length of Longest Increasing Subsequence (LIS)
int lisRecursive(vector<int>& nums, int n) {
    // Base case: if only one element is present
    if (n == 1) {
        return 1;
    }

    int maxEndingHere = 1; // Length of LIS ending at current element

    // Recursively find LIS ending at previous elements and update maxEndingHere
    for (int i = 1; i < n; ++i) {
        int subproblem = lisRecursive(nums, i);
        if (nums[i - 1] < nums[n - 1]) {
            maxEndingHere = max(maxEndingHere, 1 + subproblem);
        }
    }

    return maxEndingHere;
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18}; // Example array

    int n = nums.size();

    int lisLength = lisRecursive(nums, n);

    cout << "Length of Longest Increasing Subsequence is: " << lisLength << endl;

    return 0;
}
