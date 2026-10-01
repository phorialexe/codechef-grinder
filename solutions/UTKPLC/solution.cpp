#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Utkarsh and Placement tests
 * Approach:
 * We are given a preference order of 3 companies. We map each company to its 
 * rank (0, 1, 2) and compare the ranks of the two offers received.
 * Using a simple array for mapping is faster and safer than unordered_map.
 */

void solve() {
    char p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    
    char x, y;
    cin >> x >> y;
    
    // Map each company to its preference rank (0, 1, 2)
    // Using an array indexed by the character's ASCII value
    int rank[256];
    rank[p1] = 0;
    rank[p2] = 1;
    rank[p3] = 2;
    
    // Compare the ranks of the two offers
    if (rank[x] < rank[y]) {
        cout << x << "\n";
    } else {
        cout << y << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}