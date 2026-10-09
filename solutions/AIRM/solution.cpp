#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each airplane occupies a runway at its arrival time A_i and at its departure time D_i.
 * The problem states: "A plane uses the runway only in the minute at which it arrives or departs."
 * This means at any specific minute 't', the number of runways required is the total count 
 * of airplanes that either arrive or depart at that exact minute.
 * 
 * Since the constraints on time are small (0 <= A_i < D_i <= 1439), we can use a frequency 
 * array (or map) to count how many events (arrivals or departures) occur at each minute.
 * The minimum number of runways required is the maximum number of events occurring at any 
 * single minute across the entire day.
 * 
 * Time Complexity: O(N) per test case, where N is the number of airplanes.
 * Space Complexity: O(T_max), where T_max is the maximum time (1440 minutes).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;

    // Since time is bounded by 0 to 1439, an array of size 1440 is sufficient.
    // Using a vector to store counts for each minute.
    vector<int> counts(1440, 0);

    // Read arrival times
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        counts[a]++;
    }

    // Read departure times
    for (int i = 0; i < N; ++i) {
        int d;
        cin >> d;
        counts[d]++;
    }

    // The answer is the maximum number of planes at any single minute.
    int max_runways = 0;
    for (int i = 0; i < 1440; ++i) {
        if (counts[i] > max_runways) {
            max_runways = counts[i];
        }
    }

    cout << max_runways << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}