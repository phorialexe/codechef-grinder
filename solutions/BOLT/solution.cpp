#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The final speed of Chef is v_final = k1 * k2 * k3 * v.
 * The time taken is T = 100 / v_final.
 * We need to check if T < 9.58.
 * 
 * Note on rounding:
 * The problem states the time is rounded to 2 decimal places.
 * To avoid floating point precision issues, we can compare the rounded value.
 * A common way to round to 2 decimal places is to add a small epsilon 
 * (like 1e-9) and then check the condition.
 * 
 * Specifically, if we want to check if round(T, 2) < 9.58:
 * This is equivalent to checking if T < 9.575.
 * Why? Because any value < 9.575 will round down to 9.57 or less,
 * and any value >= 9.575 will round up to 9.58 or more.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        double k1, k2, k3, v;
        cin >> k1 >> k2 >> k3 >> v;

        // Calculate final speed
        double final_speed = k1 * k2 * k3 * v;
        
        // Calculate time taken
        double time_taken = 100.0 / final_speed;

        // We need to check if round(time_taken, 2) < 9.58.
        // Using a small epsilon to handle floating point inaccuracies.
        // The threshold for rounding to 9.58 is 9.575.
        // If time_taken < 9.575, it rounds to <= 9.57, which is < 9.58.
        if (time_taken < 9.575) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}