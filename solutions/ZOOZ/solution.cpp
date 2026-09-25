#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem: ZOOZ
 * Strategy: Construct a string starting and ending with '1', with '0's in between.
 * This ensures every '0' contributes exactly one '10' and one '01' subsequence.
 */

void solve() {
    int N;
    cin >> N;
    
    string result = "1";
    for (int i = 0; i < N - 2; ++i) {
        result += '0';
    }
    result += '1';
    
    cout << result << endl;
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