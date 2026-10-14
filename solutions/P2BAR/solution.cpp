#include <iostream>
#include <string>

using namespace std;

/**
 * Problem: P2BAR
 * Logic:
 * Iterate through the string. Maintain a flag 'silence_found'.
 * Once 'silence_found' becomes true, increment a counter for every '1' encountered.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int pulse_count = 0;
    bool silence_found = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            silence_found = true;
        } else if (S[i] == '1') {
            if (silence_found) {
                pulse_count++;
            }
        }
    }

    cout << pulse_count << endl;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        solve();
    }

    return 0;
}