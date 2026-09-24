#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * The problem asks to check if the given day X is the day of the Algomaniac finals,
 * which is March 17.
 * 
 * Logic:
 * If X == 17, print "YAY".
 * Otherwise, print "NO".
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    if (X == 17) {
        cout << "YAY" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}