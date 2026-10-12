#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Maximum: To maximize the number of people, we place them at every second urinal starting from the first.
 * For N urinals, the pattern is 1, 0, 1, 0, 1...
 * The number of people is ceil(N / 2.0), which is (N + 1) / 2.
 * 
 * Minimum: To minimize the number of people such that no more can be added, we need to ensure every 
 * empty urinal is adjacent to at least one occupied urinal.
 * For N=1: 1 person (1)
 * For N=2: 1 person (0, 1 or 1, 0)
 * For N=3: 1 person (0, 1, 0)
 * For N=4: 2 people (0, 1, 0, 1)
 * For N=5: 2 people (0, 1, 0, 1, 0)
 * For N=6: 2 people (0, 1, 0, 0, 1, 0)
 * Pattern for minimum: ceil(N / 2.0) / 2 is not quite right.
 * Let's observe:
 * N=1: 1
 * N=2: 1
 * N=3: 1
 * N=4: 2
 * N=5: 2
 * N=6: 2
 * N=7: 3
 * The formula is (N + 2) / 3? No.
 * Let's re-check:
 * N=1: 1
 * N=2: 1
 * N=3: 1
 * N=4: 2
 * N=5: 2
 * N=6: 2
 * N=7: 3
 * The pattern is ceil(N / 2.0) / 2? No.
 * Actually, the minimum number of people is ceil(N / 2.0) / 2 is wrong.
 * It is (N + 2) / 3? 
 * N=1: 1
 * N=2: 1
 * N=3: 1
 * N=4: 2
 * N=5: 2
 * N=6: 2
 * N=7: 3
 * Yes, the sequence is 1, 1, 1, 2, 2, 2, 3, 3, 3...
 * Which is (N + 2) / 3.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int max_people = (n + 1) / 2;
        int min_people = (n + 2) / 3;

        cout << max_people << " " << min_people << "\n";
    }

    return 0;
}