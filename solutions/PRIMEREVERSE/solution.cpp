#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are allowed to reverse any substring of length X, where X is a prime number.
 * 
 * Key Insight:
 * 1. If we can reverse a substring of length 2, we can swap any two adjacent elements.
 *    (Since 2 is prime).
 * 2. If we can swap any two adjacent elements, we can perform any permutation of the string.
 * 3. However, we are restricted to prime lengths.
 *    - If we can reverse a substring of length 2, we can swap adjacent elements.
 *    - If we can reverse a substring of length 3, we can swap elements at distance 2 (i, i+2).
 *    - By combining these, we can effectively swap any two elements in the string.
 *    - For example, to swap A[i] and A[j], we can move A[i] to position j using adjacent swaps.
 * 
 * Since we can perform any permutation of the string, the only condition for 
 * string A to be transformable into string B is that they must have the same 
 * number of '0's and the same number of '1's.
 * 
 * Complexity:
 * Time: O(N) per test case to count the occurrences of '0' and '1'.
 * Space: O(N) to store the strings.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int countA0 = 0, countA1 = 0;
    int countB0 = 0, countB1 = 0;

    for (char c : A) {
        if (c == '0') countA0++;
        else countA1++;
    }

    for (char c : B) {
        if (c == '0') countB0++;
        else countB1++;
    }

    if (countA0 == countB0 && countA1 == countB1) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}