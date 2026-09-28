#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef runs X km before resting. Total distance is Y km.
 * He stops at X, 2X, 3X, ... km marks.
 * He only stops if the distance is strictly less than Y.
 * 
 * If Y <= X, he finishes before or exactly at the first rest point, so 0 stops.
 * If Y > X, he stops at X, 2X, ..., kX where kX < Y.
 * The number of such stops is the largest integer k such that kX < Y.
 * This is equivalent to kX <= Y - 1, or k <= (Y - 1) / X.
 * Since k must be an integer, k = (Y - 1) / X.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    if (!(cin >> X >> Y)) return 0;

    // If Y <= X, the result of (Y - 1) / X is 0, which is correct.
    // Example: X=3, Y=3 -> (3-1)/3 = 0.
    // Example: X=4, Y=3 -> (3-1)/4 = 0.
    // Example: X=1, Y=2 -> (2-1)/1 = 1.
    // Example: X=2, Y=5 -> (5-1)/2 = 2.
    
    if (Y <= X) {
        cout << 0 << endl;
    } else {
        cout << (Y - 1) / X << endl;
    }

    return 0;
}