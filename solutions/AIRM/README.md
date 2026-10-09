# [Airport Management (AIRM)](https://www.codechef.com/problems/AIRM)

- **Difficulty Rating**: 1201
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the arrival and departure times for $N$ airplanes at an airport. A plane occupies a runway only at the exact minute it arrives and the exact minute it departs. We need to determine the minimum number of runways required such that no two planes are forced to use the same runway at the same time. Essentially, we need to find the maximum number of planes that are either arriving or departing at any single minute throughout the day.

## Intuition & Mathematical Observation
The problem states that a plane occupies a runway at its arrival time $A_i$ and its departure time $D_i$. This implies that at any specific minute $t$, the runway is "busy" if a plane arrives at $t$ or if a plane departs at $t$.

Since the time range is constrained between 0 and 1439 (representing the minutes in a 24-hour day), we can use a **frequency array** of size 1440. 
1. For every arrival time $A_i$, we increment the count at index $A_i$.
2. For every departure time $D_i$, we increment the count at index $D_i$.
3. After processing all $N$ planes, the value at any index `counts[t]` represents the total number of planes occupying a runway at minute $t$.
4. The minimum number of runways required to handle the traffic is simply the maximum value found in our frequency array, as this represents the peak demand at any single moment.

## Complexity Analysis
- **Time Complexity**: $O(N + T_{max})$, where $N$ is the number of airplanes and $T_{max}$ is the total number of minutes in a day (1440). Since $T_{max}$ is constant, this effectively simplifies to $O(N)$ per test case.
- **Space Complexity**: $O(T_{max})$, as we use a fixed-size array of 1440 integers to store the event counts.

## Solution Code

```cpp
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
 * array to count how many events (arrivals or departures) occur at each minute.
 * The minimum number of runways required is the maximum number of events occurring at any 
 * single minute across the entire day.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;

    // Since time is bounded by 0 to 1439, an array of size 1440 is sufficient.
    vector<int> counts(1440, 0);

    // Read arrival times and increment the count for that minute
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        counts[a]++;
    }

    // Read departure times and increment the count for that minute
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
```