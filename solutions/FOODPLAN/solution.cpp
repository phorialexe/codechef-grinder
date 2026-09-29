#include <iostream>

using namespace std;

/**
 * Problem: FOODPLAN
 * Logic: 
 * Online price after 10% discount = N - (N * 0.1) = 0.9 * N
 * We compare 0.9 * N with M.
 * To avoid floating point issues, multiply by 10:
 * Compare 9 * N with 10 * M.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    int online_cost_scaled = 9 * N;
    int dining_cost_scaled = 10 * M;

    if (online_cost_scaled < dining_cost_scaled) {
        cout << "ONLINE" << endl;
    } else if (online_cost_scaled > dining_cost_scaled) {
        cout << "DINING" << endl;
    } else {
        cout << "EITHER" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}