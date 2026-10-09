#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make all elements in the array equal to some value X.
 * In one move, we can change A[i] to A[i-1] or A[i+1].
 * This implies that if we want to make all elements equal to X, 
 * we can propagate the value X to any position in the array as long as 
 * there is at least one instance of X initially present in the array.
 * 
 * If we choose a target value X that is already present in the array, 
 * we can change all other elements to X. The number of moves required 
 * will be N - (count of X in the original array).
 * 
 * To minimize the number of moves, we need to maximize the count of X.
 * Therefore, we should pick X to be the most frequent element in the array.
 * The answer is N - (maximum frequency of any element).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    map<int, int> counts;
    int max_freq = 0;
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        counts[val]++;
        if (counts[val] > max_freq) {
            max_freq = counts[val];
        }
    }
    
    // The minimum moves is total elements minus the count of the most frequent element.
    cout << (N - max_freq) << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}