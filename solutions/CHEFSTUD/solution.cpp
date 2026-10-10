#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem states that students talking to the right ('>') turn to the left ('<'),
 * and students talking to the left ('<') turn to the right ('>').
 * Students studying ('*') remain unchanged.
 * 
 * Chef punishes pairs that are "talking to each other".
 * In the new configuration, a pair is talking to each other if they form the pattern "<>".
 * 
 * Let's map the transformation:
 * '>' becomes '<'
 * '<' becomes '>'
 * '*' remains '*'
 * 
 * We need to count the occurrences of the substring "<>" in the transformed string.
 * 
 * Example:
 * Original: *><*
 * Transformed: *<>*
 * Pattern "<>" found at index 1: *< >* -> Count = 1? Wait, let's re-check the example.
 * Example 2: *><* -> Transformed: *<>* -> Chef sees no students talking. Output 0.
 * Example 3: ><>< -> Transformed: <><> -> Chef sees student 2 and 3 talking. Output 1.
 * 
 * Wait, the logic is:
 * Original: '>' -> New: '<'
 * Original: '<' -> New: '>'
 * A pair is punished if they are facing each other, which means the new string has "<>".
 * 
 * Let's re-examine Example 2: *><*
 * Original: * > < *
 * New:      * < > *
 * The pattern "<>" appears at index 1. But the example says 0.
 * Ah, the problem says: "When Chef sees two students facing each other, he will assume that they were talking."
 * In *< >*, the '<' is at index 1 and '>' is at index 2. They are facing away from each other.
 * A pair is talking if they are facing each other, i.e., the pattern is "<>".
 * Wait, if the new string is *< >*, the '<' at index 1 is looking left, and '>' at index 2 is looking right.
 * They are NOT facing each other.
 * Facing each other means the pattern is "><".
 * 
 * Let's re-check Example 3: ><><
 * New: < > < >
 * Here, the pair at index 1 and 2 is "> <". They are facing each other!
 * So the pattern to count is "><".
 */

void solve() {
    string s;
    cin >> s;
    int count = 0;
    // We need to count occurrences of "><" in the transformed string.
    // Transformed string:
    // '>' becomes '<'
    // '<' becomes '>'
    // '*' stays '*'
    // So we look for "><" in the transformed string, which is equivalent to
    // looking for "<>" in the original string.
    
    for (size_t i = 0; i + 1 < s.length(); ++i) {
        if (s[i] == '<' && s[i + 1] == '>') {
            count++;
        }
    }
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}