#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * We need to maintain the count of Rs. 5 and Rs. 10 coins currently held by Chef.
 * - If customer pays 5: Chef keeps it (count5++).
 * - If customer pays 10: Chef needs 5 back. If count5 > 0, count5--, count10++. Else, fail.
 * - If customer pays 15: Chef needs 10 back.
 *      - Prefer giving a 10-rupee coin if available (count10--).
 *      - Otherwise, give two 5-rupee coins (count5 -= 2).
 *      - If neither is possible, fail.
 */

void solve() {
    int N;
    cin >> N;
    int count5 = 0;
    int count10 = 0;
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        int coin;
        cin >> coin;

        if (!possible) continue;

        if (coin == 5) {
            count5++;
        } else if (coin == 10) {
            if (count5 >= 1) {
                count5--;
                count10++;
            } else {
                possible = false;
            }
        } else if (coin == 15) {
            if (count10 >= 1) {
                count10--;
            } else if (count5 >= 2) {
                count5 -= 2;
            } else {
                possible = false;
            }
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}