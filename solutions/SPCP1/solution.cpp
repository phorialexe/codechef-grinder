#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's weight = 60 kg
 * Chef's height = 130 cm
 * Condition for entry:
 * 1. Weight <= W
 * 2. Height >= H
 * 
 * We need to check if 60 <= W AND 130 >= H.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the input format,
    // but standard competitive programming practice often involves reading until EOF 
    // or handling a specific number of test cases. Given the problem description:
    // "The first and only line of input will contain two space-separated integers W and H."
    
    long long W, H;
    if (cin >> W >> H) {
        // Chef's stats
        long long chefWeight = 60;
        long long chefHeight = 130;

        // Check conditions
        if (chefWeight <= W && chefHeight >= H) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}