#include <iostream>
#include <string>
#include <algorithm> // For max function

using namespace std;

// Recursive function to find the length of Longest Common Subsequence (LCS)
int lcsRecursive(string& s1, string& s2, int m, int n) {
    // Base case: if either of the strings is empty
    if (m == 0 || n == 0) {
        return 0;
    }

    // If characters match, include them in LCS
    if (s1[m - 1] == s2[n - 1]) {
        return 1 + lcsRecursive(s1, s2, m - 1, n - 1);
    } else {
        // Otherwise, consider two cases: excluding current character from either string
        return max(lcsRecursive(s1, s2, m, n - 1), lcsRecursive(s1, s2, m - 1, n));
    }
}

int main() {
    string s1 = "GGATTACCATTATGGAGGCGGA";
    string s2 = "ACTTAGGTAGG";

    int m = s1.length();
    int n = s2.length();

    int lcsLength = lcsRecursive(s1, s2, m, n);

    cout << "Length of Longest Common Subsequence is: " << lcsLength << endl;

    return 0;
}
