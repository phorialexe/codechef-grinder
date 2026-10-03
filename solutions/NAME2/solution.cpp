#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to check if string M is a subsequence of W OR W is a subsequence of M.
 * A string A is a subsequence of B if we can find all characters of A in B 
 * in the same relative order.
 * 
 * Algorithm:
 * To check if A is a subsequence of B:
 * 1. Use two pointers, one for A (i) and one for B (j).
 * 2. Iterate through B with j. If B[j] == A[i], increment i.
 * 3. If i reaches the length of A, then A is a subsequence of B.
 * 
 * Complexity:
 * Time Complexity: O(|M| + |W|) per test case. Given constraints |M|, |W| <= 25000,
 * this is well within the time limit for 100 test cases.
 * Space Complexity: O(|M| + |W|) to store the strings.
 */

bool isSubsequence(const string& s1, const string& s2) {
    int n = s1.length();
    int m = s2.length();
    int i = 0, j = 0;
    
    while (i < n && j < m) {
        if (s1[i] == s2[j]) {
            i++;
        }
        j++;
    }
    return i == n;
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        string m, w;
        cin >> m >> w;
        
        // Check if m is a subsequence of w OR w is a subsequence of m
        if (isSubsequence(m, w) || isSubsequence(w, m)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}