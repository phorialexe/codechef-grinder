#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef and Cook-Off
 * The task is to count the number of solved problems (sum of 1s in the input row)
 * and map that count to the corresponding developer level.
 * 
 * Time Complexity: O(N) where N is the number of competitors.
 * Space Complexity: O(1) as we process each line independently.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        int solved_count = 0;
        for (int i = 0; i < 5; ++i) {
            int val;
            cin >> val;
            if (val == 1) {
                solved_count++;
            }
        }

        // Mapping the count to the corresponding level
        if (solved_count == 0) {
            cout << "Beginner" << "\n";
        } else if (solved_count == 1) {
            cout << "Junior Developer" << "\n";
        } else if (solved_count == 2) {
            cout << "Middle Developer" << "\n";
        } else if (solved_count == 3) {
            cout << "Senior Developer" << "\n";
        } else if (solved_count == 4) {
            cout << "Hacker" << "\n";
        } else if (solved_count == 5) {
            cout << "Jeff Dean" << "\n";
        }
    }

    return 0;
}