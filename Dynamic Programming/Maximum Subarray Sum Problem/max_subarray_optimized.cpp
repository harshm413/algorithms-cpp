#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

// Function to calculate the maximum subarray sum using an optimized approach
int maxSubArrayOptimized(vector<int>& nums) {
    int maxSum = nums[0]; // Initialize the maximum sum with the first element
    int currentSum = nums[0]; // Initialize the current sum with the first element

    // Iterate over the array starting from the second element
    for (int i = 1; i < nums.size(); ++i) {
        if (currentSum < 0) {
            currentSum = nums[i];
        } else {
            currentSum += nums[i];
        }
        maxSum = max(maxSum, currentSum);
    }

    return maxSum; // Return the maximum subarray sum
}

int main() {
    vector<int> nums = {5,4,-1,7,8}; // Example array
    cout << "Maximum subarray sum using Optimized Approach: " << maxSubArrayOptimized(nums) << endl;
    return 0;
}
