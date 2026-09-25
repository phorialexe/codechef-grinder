#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef gets 30 rupees for every stick eaten beyond X.
 * Total extra sticks = R / 30.
 * Total sticks eaten = X + (R / 30).
 * Each plate contains Y sticks.
 * We need to find the number of plates required to cover the total sticks eaten.
 * Since Chef doesn't order a new plate until the previous one is finished,
 * and he might not finish the last plate, we are looking for the minimum number of plates
 * that can provide at least (X + R/30) sticks.
 * 
 * Wait, the problem asks for the *maximum* number of plates he could have ordered.
 * If he ate S = X + R/30 sticks, he must have ordered enough plates to cover S.
 * The number of plates P must satisfy: (P-1) * Y < S <= P * Y.
 * Actually, the problem says "maximum number of plates". 
 * If he ate S sticks, he could have ordered P plates such that the total capacity 
 * of P plates is at least S, but the capacity of (P-1) plates is less than S.
 * Wait, let's re-read: "Chef won't order a new plate till he finishes eating all the sticks from the previous one."
 * This implies he orders plates one by one. To eat S sticks, he needs ceil(S / Y) plates.
 * The number of plates is exactly ceil(S / Y).
 * Let's check the sample:
 * 1) X=7, Y=5, R=30. Extra = 1. Total = 8. Plates = ceil(8/5) = 2. Correct.
 * 2) X=16, Y=5, R=0. Extra = 0. Total = 16. Plates = ceil(16/5) = 4. Correct.
 * 3) X=15, Y=9, R=120. Extra = 4. Total = 19. Plates = ceil(19/9) = 3. Correct.
 * 4) X=23, Y=1, R=2130. Extra = 71. Total = 94. Plates = ceil(94/1) = 94. Correct.
 * 
 * The formula is ceil((X + R/30) / Y).
 * Using integer arithmetic: (S + Y - 1) / Y.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long X, Y, R;
        cin >> X >> Y >> R;

        long long extra_sticks = R / 30;
        long long total_sticks = X + extra_sticks;

        // Calculate ceil(total_sticks / Y) using integer division
        long long plates = (total_sticks + Y - 1) / Y;

        cout << plates << "\n";
    }

    return 0;
}