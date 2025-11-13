///Recursion

//#include <iostream>
//#include <string>
//using namespace std;
//
//int solve(string& a, string& b, int i, int j)
//{
//    if (i == a.length() || j == b.length())
//    {
//        return 0;
//    }
//    int ans = 0;
//    if (a[i] == b[j])
//    {
//        ans = 1 + solve(a, b, i + 1, j + 1);
//    }
//    else
//    {
//        ans = max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
//    }
//    return ans;
//}
//
//int longestcommonsubsequence(string text1, string text2)
//{
//    return solve(text1, text2, 0, 0);
//}
//
//int main()
//{
//    string text1, text2;
//
//    cout << "Enter the first string: ";
//    cin >> text1;
//
//    cout << "Enter the second string: ";
//    cin >> text2;
//
//    int lcs_length = longestcommonsubsequence(text1, text2);
//
//    cout << "Length of Longest Common Subsequence: " << lcs_length << endl;
//
//    return 0;
//}


///Memoization(Top-Bottom)

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
//    if (i == a.length() || j == b.length()) {
//        return 0;
//    }
//    if (dp[i][j] != -1) {
//        return dp[i][j];
//    }
//    int ans = 0;
//    if (a[i] == b[j]) {
//        ans = 1 + solve(a, b, i + 1, j + 1, dp);
//    } else {
//        ans = max(solve(a, b, i + 1, j, dp), solve(a, b, i, j + 1, dp));
//    }
//    return dp[i][j] = ans;
//}
//
//int longestcommonsubsequence(string text1, string text2) {
//    vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
//    return solve(text1, text2, 0, 0, dp);
//}

//int main() {
//    string text1, text2;
//
//    cout << "Enter the first string: ";
//    cin >> text1;
//
//    cout << "Enter the second string: ";
//    cin >> text2;
//
//    int lcs_length = longestcommonsubsequence(text1, text2);
//
//    cout << "Length of Longest Common Subsequence: " << lcs_length << endl;
//
//    return 0;
//}


///Tabular Method(Bottom-Up)
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int solveTab(string a, string b) {
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    for (int i = a.length() - 1; i >= 0; i--) {
        for (int j = b.length() - 1; j >= 0; j--) {
            int ans = 0;
            if (a[i] == b[j]) {
                ans = 1 + dp[i + 1][j + 1];
            } else {
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

///More Optimized


//int solveTab(string a, string b) {
//    vector<int> curr(b.length() + 1, 0);
//    vector<int> next(b.length() + 1, 0);
//
//    for (int i = a.length() - 1; i >= 0; i--) {
//        for (int j = b.length() - 1; j >= 0; j--) {
//            int ans = 0;
//            if (a[i] == b[j]) {
//                ans = 1 + next[j + 1];
//            } else {
//                ans = max(next[j], curr[j + 1]);
//            }
//            curr[j] = ans;
//        }
//        next = curr;
//    }
//    return next[0];
//}

int main() {
    string text1, text2;

    cout << "Enter the first string: ";
    cin >> text1;

    cout << "Enter the second string: ";
    cin >> text2;

    int lcs_length = solveTab(text1, text2);

    cout << "Length of Longest Common Subsequence: " << lcs_length << endl;

    return 0;
}


