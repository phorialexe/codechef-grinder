#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is student 1 with marks A[1].
 * To ensure Chef passes, the cutoff X must satisfy X <= A[1].
 * To minimize the number of students who pass, we want to maximize X 
 * such that X <= A[1].
 * The largest possible value for X is A[1].
 * If we set X = A[1], then any student i with A[i] >= A[1] will pass.
 * The number of students who pass is the count of students where A[i] >= A[1].
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int chef_marks = A[0];
    int count = 0;

    // We set the cutoff X = chef_marks.
    // A student passes if their marks A[i] >= X.
    // Since X = A[0], we count how many A[i] >= A[0].
    for (int i = 0; i < N; ++i) {
        if (A[i] >= chef_marks) {
            count++;
        }
    }

    cout << count << "\n";
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