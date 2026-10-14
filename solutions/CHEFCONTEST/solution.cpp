#include <iostream>

using namespace std;

/**
 * Problem: CHEFCONTEST
 * Logic:
 * Chef's penalty = X + P * 10
 * Chefina's penalty = Y + Q * 10
 * Compare the two and output the winner.
 */

void solve() {
    int X, Y, P, Q;
    if (!(cin >> X >> Y >> P >> Q)) return;

    int chef_penalty = X + (P * 10);
    int chefina_penalty = Y + (Q * 10);

    if (chef_penalty < chefina_penalty) {
        cout << "Chef" << endl;
    } else if (chefina_penalty < chef_penalty) {
        cout << "Chefina" << endl;
    } else {
        cout << "Draw" << endl;
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        solve();
    }

    return 0;
}