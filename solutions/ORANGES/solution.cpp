#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N oranges, each having 10, 11, or 12 slices.
 * The total number of slices K must satisfy:
 * Minimum possible slices = N * 10
 * Maximum possible slices = N * 12
 * 
 * Since we can choose any combination of 10, 11, or 12 slices for each of the N oranges,
 * we can achieve any integer sum K such that:
 * (N * 10) <= K <= (N * 12)
 * 
 * Proof:
 * If we have N oranges, we start with N * 10 slices (all oranges have 10).
 * We can increment the total by 1 by changing one orange from 10 to 11 slices.
 * We can continue this until all N oranges have 11 slices (total N * 11).
 * Then we can change one orange from 11 to 12 slices, incrementing the total by 1,
 * until all N oranges have 12 slices (total N * 12).
 * Thus, every integer value between N*10 and N*12 is reachable.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long min_slices = n * 10;
        long long max_slices = n * 12;

        if (k >= min_slices && k <= max_slices) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}