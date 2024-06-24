#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the maximum crossing subarray sum
int maxCrossingSum(vector<int>& arr, int left, int mid, int right) {
    int sum = 0;
    int left_sum = INT_MIN;
    
    // Include elements on left of mid
    for (int i = mid; i >= left; --i) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;

    // Include elements on right of mid
    for (int i = mid + 1; i <= right; ++i) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    // Return sum of elements on left and right of mid
    // Including arr[mid]
    return left_sum + right_sum;
}

// Function to find the maximum subarray sum using divide and conquer
int maxSubArraySum(vector<int>& arr, int left, int right) {
    // No element
    if (left > right) {
        return -1;
    }

    // Base case: only one element
    if (left == right) {
        return arr[left];
    }

    // Find middle point
    int mid = left + (right - left) / 2;

    // Return maximum of following three possible cases:
    // a) Maximum subarray sum in left half
    // b) Maximum subarray sum in right half
    // c) Maximum subarray sum such that the subarray crosses the midpoint
    return max(maxSubArraySum(arr, left, mid),
                max(maxSubArraySum(arr, mid + 1, right),
                maxCrossingSum(arr, left, mid, right)));
}

int main() {
    vector<int> arr = {5,4,-1,7,8};
    int n = arr.size();
    int max_sum = maxSubArraySum(arr, 0, n - 1);

    cout << "Maximum subarray sum is: " << max_sum << endl;

    return 0;
}
