#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three sizes: S, L, XL.
 * Available: X (S), Y (L), Z (XL)
 * Demand: A (S), B (L), C (XL)
 * 
 * Rules:
 * 1. XL can become L or S.
 * 2. L can become S.
 * 3. We want to maximize the number of happy people.
 * 
 * Strategy:
 * - XL people must be satisfied by XL shirts first (since XL is the most versatile).
 * - L people should be satisfied by L shirts, and if not enough, by XL shirts.
 * - S people should be satisfied by S shirts, then L shirts, then XL shirts.
 * 
 * Greedy approach:
 * 1. Satisfy XL demand (C) using available XL shirts (Z).
 *    - Happy_XL = min(Z, C)
 *    - Remaining XL = Z - Happy_XL
 *    - Remaining Demand_C = C - Happy_XL
 * 
 * 2. Satisfy L demand (B) using available L shirts (Y) and remaining XL shirts.
 *    - Available L = Y + Remaining XL
 *    - Happy_L = min(Available L, B)
 *    - Remaining L = Available L - Happy_L
 * 
 * 3. Satisfy S demand (A) using available S shirts (X) and remaining L/XL shirts.
 *    - Available S = X + Remaining L
 *    - Happy_S = min(Available S, A)
 * 
 * Total Happy = Happy_XL + Happy_L + Happy_S
 */

void solve() {
    long long X, Y, Z, A, B, C;
    cin >> X >> Y >> Z >> A >> B >> C;

    long long happy_xl = min(Z, C);
    long long rem_z = Z - happy_xl;

    long long available_l = Y + rem_z;
    long long happy_l = min(available_l, B);
    long long rem_l = available_l - happy_l;

    long long available_s = X + rem_l;
    long long happy_s = min(available_s, A);

    cout << happy_xl + happy_l + happy_s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}