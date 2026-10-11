#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form a rectangle, we need two pairs of equal length sticks.
 * Let the lengths of the two pairs be 'a' and 'b'.
 * The area of the rectangle will be a * b.
 * To maximize the area, we need to pick the two largest possible pairs available.
 * 
 * Algorithm:
 * 1. Count the frequency of each stick length or sort the array.
 * 2. Sorting the array in descending order allows us to easily pick the largest pairs.
 * 3. Iterate through the sorted array and identify pairs (two identical adjacent elements).
 * 4. The first pair found will be the largest side 'a', the second pair found will be 'b'.
 * 5. If we find two pairs, the answer is a * b. Otherwise, return -1.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort in descending order to find the largest pairs first
    sort(a.rbegin(), a.rend());

    long long side1 = -1;
    long long side2 = -1;

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) {
            if (side1 == -1) {
                side1 = a[i];
                // Skip the next element as it's part of the pair
                i++;
            } else {
                side2 = a[i];
                break;
            }
        }
    }

    if (side1 != -1 && side2 != -1) {
        cout << side1 * side2 << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}