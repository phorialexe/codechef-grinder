#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Operation 1 allows converting any uppercase letter to its lowercase equivalent.
 *    This means we can effectively treat every uppercase letter 'X' as a potential 
 *    lowercase letter 'x'.
 * 2. Operation 2 allows us to pick one lowercase letter and change all its 
 *    occurrences to another lowercase letter.
 * 
 * Strategy:
 * - First, convert all uppercase letters to their lowercase equivalents.
 *   After this, we have a string consisting only of lowercase letters.
 * - Let the frequency of each lowercase character 'a'-'z' be count[char].
 * - Operation 2 allows us to merge the counts of two different characters.
 *   If we choose to merge character 'x' into character 'y', the new count of 'y'
 *   becomes count[y] + count[x].
 * - To maximize the score, we should pick the two characters with the highest 
 *   frequencies and merge them.
 * - If there is only one type of character or the string is empty, the score is 
 *   simply the count of that character.
 * - Since we can perform Operation 2 exactly once, we take the two largest 
 *   frequencies and sum them.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N == 0) {
        cout << 0 << "\n";
        return;
    }

    vector<int> counts(26, 0);
    for (char c : S) {
        if (c >= 'A' && c <= 'Z') {
            counts[c - 'A']++;
        } else {
            counts[c - 'a']++;
        }
    }

    // Sort frequencies to find the two largest
    sort(counts.rbegin(), counts.rend());

    // The maximum score is the sum of the two most frequent characters.
    // Even if we don't strictly need to perform Operation 2, 
    // merging the top two covers the case where we merge a character 
    // into itself or merge two different characters.
    cout << counts[0] + counts[1] << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}