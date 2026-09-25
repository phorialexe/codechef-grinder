#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - 'I' gesture: Only Indians use this. If 'I' is present, the person is INDIAN.
 * - 'Y' gesture: Only foreigners use this. If 'Y' is present (and no 'I'), the person is NOT INDIAN.
 * - 'N' gesture: Both might use this. If only 'N's are present, we are NOT SURE.
 * 
 * Logic:
 * 1. Iterate through the string.
 * 2. If 'I' is found, return "INDIAN".
 * 3. If 'Y' is found, return "NOT INDIAN".
 * 4. If the loop finishes without finding 'I' or 'Y', return "NOT SURE".
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool found_i = false;
    bool found_y = false;

    for (char c : s) {
        if (c == 'I') {
            found_i = true;
            break;
        } else if (c == 'Y') {
            found_y = true;
        }
    }

    if (found_i) {
        cout << "INDIAN" << "\n";
    } else if (found_y) {
        cout << "NOT INDIAN" << "\n";
    } else {
        cout << "NOT SURE" << "\n";
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