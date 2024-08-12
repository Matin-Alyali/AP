#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubstring(string s1, string s2) {

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    int n = s1.length();
    int m = s2.length();

    // Create a table to store the lengths of common substrings
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxLen = 0;

    // Fill the table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }

    return maxLen;
}

int main() {
    string s1, s2;
    
    cin >> s1;
   
    cin >> s2;

    int result1 = longestCommonSubstring(s1, s2);
    reverse(s1.begin(), s1.end());
    int result2 = longestCommonSubstring(s1,s2);
    cout <<  max(result1, result2);

    return 0;
}
