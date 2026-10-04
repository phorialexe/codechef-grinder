#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Mapping based on standard visual hole counting:
 * 1 hole: A, D, O, P, Q, R
 * 2 holes: B
 * 0 holes: C, E, F, G, H, I, J, K, L, M, N, S, T, U, V, W, X, Y, Z
 */

int get_holes(char c) {
    if (c == 'B') return 2;
    if (c == 'A' || c == 'D' || c == 'O' || c == 'P' || c == 'Q' || c == 'R') return 1;
    return 0;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        string s;
        cin >> s;
        int total_holes = 0;
        for (char c : s) {
            total_holes += get_holes(c);
        }
        cout << total_holes << "\n";
    }
    return 0;
}