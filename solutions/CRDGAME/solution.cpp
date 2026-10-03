#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef and Card Game
 * Approach:
 * 1. For each test case, initialize Chef's points (chef_pts) and Morty's points (morty_pts) to 0.
 * 2. For each round, calculate the sum of digits for both Chef's card and Morty's card.
 * 3. Compare the sums:
 *    - If Chef's sum > Morty's sum, Chef gets 1 point.
 *    - If Morty's sum > Chef's sum, Morty gets 1 point.
 *    - If they are equal, both get 1 point.
 * 4. After all rounds, compare total points to determine the winner.
 * 5. Time Complexity: O(T * N * log10(max(A_i, B_i))), which is well within the 1s limit.
 */

long long get_digit_sum(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void solve() {
    int N;
    cin >> N;
    
    int chef_pts = 0;
    int morty_pts = 0;
    
    for (int i = 0; i < N; ++i) {
        long long A, B;
        cin >> A >> B;
        
        long long power_A = get_digit_sum(A);
        long long power_B = get_digit_sum(B);
        
        if (power_A > power_B) {
            chef_pts++;
        } else if (power_B > power_A) {
            morty_pts++;
        } else {
            chef_pts++;
            morty_pts++;
        }
    }
    
    if (chef_pts > morty_pts) {
        cout << 0 << " " << chef_pts << "\n";
    } else if (morty_pts > chef_pts) {
        cout << 1 << " " << morty_pts << "\n";
    } else {
        cout << 2 << " " << chef_pts << "\n";
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