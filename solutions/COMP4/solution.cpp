#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Competition of 4
 * The prize money is given by the formula: 1000 * 2^(4 - X)
 * Given constraints: 1 <= X <= 4
 * 
 * Rank 1: 1000 * 2^3 = 8000
 * Rank 2: 1000 * 2^2 = 4000
 * Rank 3: 1000 * 2^1 = 2000
 * Rank 4: 1000 * 2^0 = 1000
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // The problem description implies a single input X per run, 
    // but standard competitive programming practice often involves 
    // reading until EOF or handling a single case.
    if (cin >> X) {
        long long prize = 1000LL * (1LL << (4 - X));
        cout << prize << "\n";
    }

    return 0;
}