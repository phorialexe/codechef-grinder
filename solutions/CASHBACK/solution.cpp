#include <iostream>

using namespace std;

/**
 * Problem: CASHBACK
 * Logic: If the price X is >= 200, the customer pays X - 50.
 * Otherwise, the customer pays X.
 * Input Format: Single integer X.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    // Read the single integer X as specified in the problem description
    if (cin >> x) {
        if (x >= 200) {
            cout << (x - 50) << endl;
        } else {
            cout << x << endl;
        }
    }

    return 0;
}