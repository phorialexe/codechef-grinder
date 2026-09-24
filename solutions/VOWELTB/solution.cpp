#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Is it a VOWEL or CONSONANT
 * The problem asks to identify if a given uppercase character is a vowel (A, E, I, O, U)
 * or a consonant.
 * 
 * Time Complexity: O(1) per character
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    if (!(cin >> c)) return 0;

    // Check if the character is one of the vowels
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        cout << "Vowel" << "\n";
    } else {
        cout << "Consonant" << "\n";
    }

    return 0;
}