#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For max function

using namespace std;

// Function to find the length of Longest Common Subsequence (LCS) using tabulation
int longestCommonSubsequence(string& s1, string& s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a 2D DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the DP table in bottom-up manner
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[m][n]; // Return the length of LCS
}

int main() {
    string s1 = "GGATTACACATTACCTATAGGTATAAT";
    string s2 = "GGATTTATCTATAAATTACCTATTTATTATATTACCGTATGGTATGC";

    int lcsLength = longestCommonSubsequence(s1, s2);

    cout << "Length of Longest Common Subsequence is: " << lcsLength << endl;

    return 0;
}
