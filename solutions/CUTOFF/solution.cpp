#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N students with distinct scores.
 * Exactly X students pass the test.
 * A student passes if their score > passing_mark.
 * To maximize the passing_mark, we want the smallest score among the 
 * top X students to be as high as possible, such that the passing_mark 
 * is just below that score.
 * 
 * 1. Sort the scores in descending order.
 * 2. The X-th student (index X-1 in 0-indexed sorted array) is the one 
 *    with the lowest score among those who passed.
 * 3. Let this score be S. Any passing_mark < S will allow this student to pass.
 * 4. To maximize the passing_mark while keeping exactly X students passing,
 *    the passing_mark should be S - 1.
 */

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort in descending order to easily pick the X-th highest score
    sort(A.begin(), A.end(), greater<int>());

    // The student at index X-1 is the one with the lowest score among the X passers.
    // If the passing mark is A[X-1] - 1, then A[X-1] > passing_mark,
    // and A[X] (if it exists) will be <= A[X-1] - 1.
    // Thus, exactly X students pass.
    cout << A[X - 1] - 1 << "\n";
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