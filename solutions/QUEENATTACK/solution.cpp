#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A Queen at (X, Y) on an N x N board attacks:
 * 1. Horizontal: All cells in row X except (X, Y). Total: N - 1.
 * 2. Vertical: All cells in column Y except (X, Y). Total: N - 1.
 * 3. Diagonals:
 *    - Main diagonal direction (\): Cells (r, c) where r - c = X - Y.
 *    - Anti-diagonal direction (/): Cells (r, c) where r + c = X + Y.
 * 
 * Number of cells in the main diagonal (\) passing through (X, Y):
 * The condition is r - c = X - Y.
 * Let k = X - Y. Then r - c = k => c = r - k.
 * Since 1 <= r <= N and 1 <= r - k <= N:
 * 1 <= r <= N and 1 + k <= r <= N + k.
 * The range for r is [max(1, 1 + k), min(N, N + k)].
 * Number of cells = min(N, N + k) - max(1, 1 + k) + 1.
 * Subtract 1 for the Queen's position.
 * 
 * Number of cells in the anti-diagonal (/) passing through (X, Y):
 * The condition is r + c = X + Y.
 * Let s = X + Y. Then c = s - r.
 * Since 1 <= r <= N and 1 <= s - r <= N:
 * 1 <= r <= N and s - N <= r <= s - 1.
 * The range for r is [max(1, s - N), min(N, s - 1)].
 * Number of cells = min(N, s - 1) - max(1, s - N) + 1.
 * Subtract 1 for the Queen's position.
 */

void solve() {
    long long N, X, Y;
    cin >> N >> X >> Y;

    // Horizontal and Vertical
    long long horizontal = N - 1;
    long long vertical = N - 1;

    // Main diagonal (\)
    long long k = X - Y;
    long long min_r_main = max(1LL, 1 + k);
    long long max_r_main = min(N, N + k);
    long long main_diag = (max_r_main - min_r_main + 1) - 1;

    // Anti-diagonal (/)
    long long s = X + Y;
    long long min_r_anti = max(1LL, s - N);
    long long max_r_anti = min(N, s - 1);
    long long anti_diag = (max_r_anti - min_r_anti + 1) - 1;

    cout << horizontal + vertical + main_diag + anti_diag << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}