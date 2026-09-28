#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Starting at (0, 0):
 * 1. Move A units along positive X: (A, 0)
 * 2. Move B units along positive Y: (A, B)
 * 3. Move C units along negative X: (A - C, B)
 * 4. Move D units along negative Y: (A - C, B - D)
 * 
 * The final position is (A - C, B - D).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C, D;
    if (!(cin >> A >> B >> C >> D)) return 0;

    int final_x = A - C;
    int final_y = B - D;

    cout << final_x << " " << final_y << endl;

    return 0;
}