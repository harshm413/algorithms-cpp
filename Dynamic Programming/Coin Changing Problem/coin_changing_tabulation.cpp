#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// Function to calculate the minimum coins using dynamic programming (tabulation)
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; // Base case: 0 coins needed to make up amount 0

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 4, 7, 9, 16, 43};
    int amount = 82;
    int result = coinChange(coins, amount);
    if (result != -1) {
        cout << "Minimum coins needed: " << result << endl;
    } else {
        cout << "Amount cannot be made up by any combination of the given coins." << endl;
    }

    return 0;
}
