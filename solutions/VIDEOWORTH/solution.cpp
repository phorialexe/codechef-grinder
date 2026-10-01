#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Frames per second = 24
 * - Worth per frame = 1000 words
 * - Duration = S seconds
 * - Total frames = S * 24
 * - Total worth = (S * 24) * 1000 = S * 24000
 * 
 * Constraints:
 * - T <= 100
 * - S <= 100
 * - Max output = 100 * 24000 = 2,400,000.
 * - This fits comfortably within a standard 32-bit integer, 
 *   but using long long is good practice for competitive programming.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long s;
        cin >> s;
        
        // Calculate total worth
        // 24 frames/sec * 1000 words/frame = 24000 words/sec
        long long total_worth = s * 24000;
        
        cout << total_worth << "\n";
    }
    
    return 0;
}