#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The function f(X) is a composition of clamp functions.
 * A clamp function C_i(Y) = max(A_i, min(B_i, Y)).
 * We want to find max(f(X)) where f(X) = C_N(C_{N-1}(...C_1(X)...)).
 * 
 * Since the constraints are small (N <= 100, A_i, B_i <= 100),
 * we can observe that the function f(X) is non-decreasing.
 * The range of possible values for f(X) is bounded by [min(A_i), max(B_i)].
 * Given the constraints 1 <= A_i <= B_i <= 100, we can simply simulate
 * the process for every possible integer X in the range [1, 100] 
 * and pick the maximum result.
 */

int solve_f(int X, int N, const vector<pair<int, int>>& pairs) {
    int Y = X;
    for (int i = 0; i < N; ++i) {
        if (Y < pairs[i].first) {
            Y = pairs[i].first;
        } else if (Y > pairs[i].second) {
            Y = pairs[i].second;
        }
    }
    return Y;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> pairs(N);
        for (int i = 0; i < N; ++i) {
            cin >> pairs[i].first >> pairs[i].second;
        }

        int max_val = -1;
        // The output is guaranteed to be within the range of possible A_i, B_i values.
        // Testing X from 1 to 100 is sufficient given the constraints.
        for (int X = 1; X <= 100; ++X) {
            max_val = max(max_val, solve_f(X, N, pairs));
        }
        cout << max_val << "\n";
    }
    return 0;
}