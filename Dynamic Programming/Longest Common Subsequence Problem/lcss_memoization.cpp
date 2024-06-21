#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For max function

using namespace std;

// Recursive function with memoization to find the length of LCS
int lcsMemo(string& s1, string& s2, int m, int n, vector<vector<int>>& memo) {
    // Base case: if either of the strings is empty
    if (m == 0 || n == 0) {
        return 0;
    }

    // If result is already computed, return it from memoization table
    if (memo[m][n] != -1) {
        return memo[m][n];
    }

    // If characters match, include them in LCS
    if (s1[m - 1] == s2[n - 1]) {
        return memo[m][n] = 1 + lcsMemo(s1, s2, m - 1, n - 1, memo);
    } else {
        // Otherwise, consider two cases: excluding current character from either string
        return memo[m][n] = max(lcsMemo(s1, s2, m, n - 1, memo), lcsMemo(s1, s2, m - 1, n, memo));
    }
}

int longestCommonSubsequence(string& s1, string& s2) {
    int m = s1.length();
    int n = s2.length();

    // Initialize memoization table with -1
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

    return lcsMemo(s1, s2, m, n, memo);
}

int main() {
    string s1 = "GGATTACACATTACCTATAGGTATAAT";
    string s2 = "GGATTTATCTATAAATTACCTATTTATTATATTACCGTATGGTATGC";

    int lcsLength = longestCommonSubsequence(s1, s2);

    cout << "Length of Longest Common Subsequence is: " << lcsLength << endl;

    return 0;
}
