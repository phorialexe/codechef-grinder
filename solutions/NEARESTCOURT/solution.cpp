#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two points X and Y on a number line. We want to find a point Z such that
 * max(|X - Z|, |Y - Z|) is minimized.
 * 
 * Let D = |X - Y|. The midpoint between X and Y is (X + Y) / 2.
 * If we choose Z to be the midpoint, the distance for both is D / 2.
 * 
 * If D is even, the midpoint is an integer, and the distance is D / 2.
 * If D is odd, the midpoint is X.5, so we choose either floor(midpoint) or ceil(midpoint).
 * In this case, one person travels (D-1)/2 and the other travels (D+1)/2.
 * The maximum of these is (D+1)/2.
 * 
 * This can be summarized as ceil(D / 2.0), which is equivalent to (D + 1) / 2 using integer division.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Calculate the absolute distance between X and Y
        long long diff = abs(x - y);
        
        // The minimum maximum distance is ceil(diff / 2.0)
        // Using integer arithmetic: (diff + 1) / 2
        long long result = (diff + 1) / 2;
        
        cout << result << "\n";
    }
    
    return 0;
}