#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string D consisting of '0's and '1's.
 * We want to make all digits the same by flipping exactly one digit.
 * 
 * Let count0 be the number of '0's and count1 be the number of '1's.
 * 
 * Case 1: Make all digits '1'.
 * This is possible if we have exactly one '0' and the rest are '1's.
 * i.e., count0 == 1 and count1 == (length - 1).
 * 
 * Case 2: Make all digits '0'.
 * This is possible if we have exactly one '1' and the rest are '0's.
 * i.e., count1 == 1 and count0 == (length - 1).
 * 
 * Combining these, we need (count0 == 1 && count1 == length - 1) 
 * OR (count1 == 1 && count0 == length - 1).
 * 
 * This simplifies to: (count0 == 1 && count1 == length - 1) || (count1 == 1 && count0 == length - 1).
 * Note: If length is 1, the condition is technically impossible to satisfy by flipping 
 * "exactly one" digit to make it "all same" if we consider the definition strictly, 
 * but the problem implies we change one digit. If length is 1, flipping it makes it 
 * the other digit, which is still "all same". However, the sample cases and logic 
 * suggest we count the occurrences.
 */

void solve() {
    string s;
    cin >> s;
    
    int count0 = 0;
    int count1 = 0;
    
    for (char c : s) {
        if (c == '0') count0++;
        else count1++;
    }
    
    // To make all digits '1', we need exactly one '0' and the rest '1's.
    // To make all digits '0', we need exactly one '1' and the rest '0's.
    if ((count0 == 1 && count1 == (int)s.length() - 1) || 
        (count1 == 1 && count0 == (int)s.length() - 1)) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}