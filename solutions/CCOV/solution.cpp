#include <iostream>

using namespace std;

/**
 * Problem: CCOV
 * Strategy: Compare the input speed S with the limit 40.
 * If S > 40, Alice is fined (YES). Otherwise, she is not (NO).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int S;
    if (!(cin >> S)) return 0;

    if (S > 40) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}