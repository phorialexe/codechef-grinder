#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to delete a subsequence of maximum length such that the remaining 
 * characters form a palindrome of length > 1.
 * Let the original string be S of length N.
 * If we keep a subsequence of length K that forms a palindrome, the number of 
 * characters deleted is N - K. To maximize N - K, we must minimize K.
 * However, the problem asks for the maximum length of the deleted subsequence,
 * which is equivalent to finding the shortest possible palindrome subsequence 
 * that can be formed from the original string S.
 * 
 * Actually, wait: The problem asks to delete a subsequence to leave a palindrome.
 * If we keep a subsequence that forms a palindrome, the remaining characters 
 * are just the characters of that subsequence in their original relative order.
 * Any palindrome of length > 1 must contain at least two characters.
 * If there exists any character that appears at least twice in the string, 
 * we can always form a palindrome of length 2 (e.g., "aa").
 * If we can form a palindrome of length 2, we keep those 2 characters and 
 * delete the other N-2 characters. This is the maximum possible deletion.
 * 
 * What if no character appears twice? Then every character is unique.
 * A palindrome of length > 1 requires at least one character to repeat 
 * (like "aa") or a structure like "aba". If all characters are unique, 
 * no palindrome of length > 1 can be formed.
 * 
 * Therefore:
 * 1. Count the frequency of each character.
 * 2. If any character appears >= 2 times, the answer is N - 2.
 * 3. If all characters are unique, it is impossible to form a palindrome 
 *    of length > 1, so output -1.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    map<char, int> freq;
    bool possible = false;
    for (char c : S) {
        freq[c]++;
        if (freq[c] >= 2) {
            possible = true;
        }
    }

    if (possible) {
        cout << N - 2 << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}