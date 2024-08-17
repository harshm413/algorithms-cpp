#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;

// Function to calculate the maximum subarray sum using brute force approach
int maxSubArrayBruteForce(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN; // Initialize with the smallest possible value

    // Iterate over all possible starting points for subarrays
    for (int i = 0; i < n; ++i) {
        int currentSum = 0;
        // For each starting point, calculate the sum of all subarrays that start at index i
        for (int j = i; j < n; ++j) {
            currentSum += nums[j]; // Add element at index j to the current sum
            maxSum = max(maxSum, currentSum); // Update the maximum sum
        }
    }

    return maxSum; // Return the maximum subarray sum
}

int main() {
    vector<int> nums = {5,4,-1,7,8}; // Example array
    cout << "Maximum subarray sum using Brute Force: " << maxSubArrayBruteForce(nums) << endl;
    return 0;
}
