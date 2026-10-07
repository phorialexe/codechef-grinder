#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to partition array A into two non-empty subsequences S1 and S2 such that
 * sum(S1) * sum(S2) is odd.
 * 
 * For the product of two integers to be odd, both integers must be odd.
 * Let sum(S1) = O1 (odd) and sum(S2) = O2 (odd).
 * The total sum of the array is sum(A) = sum(S1) + sum(S2) = O1 + O2.
 * Since the sum of two odd numbers is always even, the total sum of the array
 * must be even for a solution to exist.
 * 
 * Furthermore, to get an odd sum from a subsequence, we need at least one odd number.
 * If we have at least two odd numbers in the array, we can put one odd number in S1
 * and the rest of the odd numbers (if any) and all even numbers in S2.
 * Since the total sum is even, if we have an even number of odd integers, 
 * sum(S1) will be odd and sum(S2) will be (TotalSum - Odd) = Odd.
 * 
 * If the number of odd integers is 0, the sum of any subsequence is even, 
 * so the product is even.
 * If the number of odd integers is 1, the total sum is odd, so no partition works.
 * If the number of odd integers is >= 2 and the total sum is even, we can always
 * partition them such that both sums are odd.
 * 
 * Conclusion:
 * The condition is satisfied if and only if the count of odd numbers in the array is exactly 2.
 * Wait, let's re-check:
 * If count of odd numbers is 2:
 * S1 = {odd1}, S2 = {odd2, all evens}. sum(S1) = odd, sum(S2) = odd + even = odd.
 * Product = odd * odd = odd. YES.
 * If count of odd numbers is 4:
 * S1 = {odd1}, S2 = {odd2, odd3, odd4, all evens}. sum(S1) = odd, sum(S2) = odd + odd + odd + even = odd.
 * Product = odd * odd = odd. YES.
 * 
 * Actually, the condition is simply:
 * 1. The total number of odd integers must be even and at least 2.
 * 2. If the total number of odd integers is 0, the sum is even, but any subsequence sum is even.
 *    So we need at least one odd number in each subsequence.
 * 
 * Correct logic:
 * We need sum(S1) to be odd and sum(S2) to be odd.
 * This is possible if and only if the total count of odd numbers in the array is even and >= 2.
 */

void solve() {
    int N;
    cin >> N;
    int odd_count = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        if (a % 2 != 0) {
            odd_count++;
        }
    }

    if (odd_count >= 2 && odd_count % 2 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}