#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

// Function to calculate the maximum subarray sum using Kadane's Algorithm
int maxSubArrayKadane(vector<int>& nums) {
    int n = nums.size();
    int maxEndingHere = nums[0]; // Tracks the maximum subarray sum ending at the current element
    int maxSoFar = nums[0];      // Tracks the overall maximum subarray sum found so far

    // Iterate over the array starting from the second element
    for (int i = 1; i < n; ++i) {
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar; // Return the maximum subarray sum
}

int main() {
    vector<int> nums = {5,4,-1,7,8}; // Example array
    cout << "Maximum subarray sum using Kadane's Algorithm: " << maxSubArrayKadane(nums) << endl;
    return 0;
}
