#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let A be the number of problems Alice has and B be the number of problems Bob has.
 * 
 * Operation 1: Alice solves a problem.
 * A -> A - 1
 * B -> B + 1
 * The difference (A - B) changes by: (A - 1) - (B + 1) = A - B - 2.
 * 
 * Operation 2: Bob solves a problem.
 * A -> A + 3
 * B -> B - 1
 * The difference (A - B) changes by: (A + 3) - (B - 1) = A - B + 4.
 * 
 * Let D = A - B.
 * Operation 1 changes D by -2.
 * Operation 2 changes D by +4.
 * 
 * We want to reach a state where A = B, which means D = 0.
 * Starting from initial difference D_0 = N - M, we want to know if there exist 
 * non-negative integers x (number of times Alice solves) and y (number of times Bob solves)
 * such that:
 * D_0 - 2x + 4y = 0
 * 2x - 4y = D_0
 * 2(x - 2y) = D_0
 * 
 * This implies that D_0 must be divisible by 2.
 * Since D_0 = N - M, (N - M) must be even.
 * (N - M) is even if and only if (N + M) is even, or simply if N and M have the same parity.
 * 
 * Additionally, we must ensure that we don't run out of problems to solve.
 * However, since we can perform operations as long as the person has at least 1 problem,
 * and the problem asks if it is *possible* to reach equality, we check the parity condition.
 * 
 * For N=2, M=3: N-M = -1 (odd). Output NO.
 * For N=4, M=2: N-M = 2 (even). Output YES.
 * For N=1, M=5: N-M = -4 (even). Output YES.
 * For N=2, M=2: N-M = 0 (even). Output YES.
 * 
 * The condition is simply (N - M) % 2 == 0.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // Check if the difference is even
        if ((n - m) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}