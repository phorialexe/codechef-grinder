#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Volume Comparison
 * The volume of a cuboid is A * B * C.
 * The volume of a cube is X * X * X.
 * We compare these two values and output the result.
 * Constraints are small (up to 10), so standard integer types are sufficient,
 * but using long long is good practice to prevent overflow in similar problems.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B, C, X;
    // The problem description implies a single test case based on the input format,
    // but we structure it to handle input as specified.
    if (cin >> A >> B >> C >> X) {
        long long vol_cuboid = A * B * C;
        long long vol_cube = X * X * X;

        if (vol_cuboid > vol_cube) {
            cout << "Cuboid" << "\n";
        } else if (vol_cube > vol_cuboid) {
            cout << "Cube" << "\n";
        } else {
            cout << "Equal" << "\n";
        }
    }

    return 0;
}