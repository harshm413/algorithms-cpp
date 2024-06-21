#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// Helper function to calculate the minimum coins using memoization
int minCoinsMemo(vector<int>& coins, int amount, vector<int>& memo) {
    if (amount == 0) {
        return 0;
    }
    if (amount < 0) {
        return INT_MAX;
    }
    if (memo[amount] != -1) {
        return memo[amount];
    }

    int minCoins = INT_MAX;
    for (int coin : coins) {
        int res = minCoinsMemo(coins, amount - coin, memo);
        if (res != INT_MAX) { //because we are adding 1 coin to INT_MAX which can lead to overflow
            minCoins = min(minCoins, res + 1);
        }
    }

    memo[amount] = minCoins;
    return minCoins;
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> memo(amount + 1, -1);
    int result = minCoinsMemo(coins, amount, memo);
    return result == INT_MAX ? -1 : result;
}

int main() {
    vector<int> coins = {1, 4, 7, 9, 16, 43};
    int amount = 85;
    int result = coinChange(coins, amount);
    if (result != -1) {
        cout << "Minimum coins needed: " << result << endl;
    } else {
        cout << "Amount cannot be made up by any combination of the given coins." << endl;
    }

    return 0;
}
