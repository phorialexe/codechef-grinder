#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has score X and N opponents with scores A_i.
 * Rank = (number of A_i > X) + 1.
 * Sabotage: Choose index i, set A_i = 0, X = X + 100.
 * We can perform this at most K times.
 * 
 * Strategy:
 * To minimize rank, we want to minimize the number of opponents with A_i > X.
 * Each sabotage operation does two things:
 * 1. Removes an opponent from the "greater than X" set (if A_i > X).
 * 2. Increases X, which might remove other opponents from the "greater than X" set.
 * 
 * Since we want to minimize the count of A_i > X, we should prioritize sabotaging 
 * the opponents who currently have the highest scores. This is because sabotaging 
 * a high score removes it from the count and increases X, which helps reduce 
 * the count of other high scores.
 * 
 * Algorithm:
 * 1. Sort the opponent scores in descending order.
 * 2. Iterate through the sabotage count from 0 to K.
 * 3. For a fixed number of sabotages 's' (0 <= s <= K):
 *    - The first 's' opponents (the ones with the highest scores) are set to 0.
 *    - Chef's new score becomes X + s * 100.
 *    - Count how many of the remaining (N - s) opponents have scores > (X + s * 100).
 *    - The rank is this count + 1.
 * 4. The answer is the minimum rank found across all possible s from 0 to K.
 */

void solve() {
    int N;
    long long X, K;
    cin >> N >> X >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort descending to sabotage the largest scores first
    sort(A.begin(), A.end(), greater<long long>());

    int min_rank = N + 1;

    // Try performing sabotage 's' times, where 0 <= s <= K
    for (int s = 0; s <= K; ++s) {
        long long current_X = X + (long long)s * 100;
        int count_greater = 0;
        
        // After sabotaging s opponents, the first s elements are 0.
        // We only check the remaining N - s elements.
        for (int i = s; i < N; ++i) {
            if (A[i] > current_X) {
                count_greater++;
            }
        }
        
        int current_rank = count_greater + 1;
        if (current_rank < min_rank) {
            min_rank = current_rank;
        }
    }

    cout << min_rank << "\n";
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