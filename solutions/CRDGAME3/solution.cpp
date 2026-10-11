#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To minimize the number of digits for a given power P, a player should use as many 9s as possible.
 * If the power is P, the number of digits required is ceil(P / 9).
 * In integer arithmetic, ceil(P / 9) can be calculated as (P + 8) / 9.
 * 
 * Let D_C be the number of digits for Chef: D_C = (P_C + 8) / 9
 * Let D_R be the number of digits for Rick: D_R = (P_R + 8) / 9
 * 
 * Rules:
 * 1. The player with fewer digits wins.
 * 2. If D_C == D_R, Rick wins (Rick cheats).
 * 
 * Therefore:
 * If D_C <= D_R, Chef wins (Wait, the rule says if equal, Rick wins).
 * So:
 * If D_C < D_R, Chef wins.
 * If D_R <= D_C, Rick wins.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long pc, pr;
        cin >> pc >> pr;

        // Calculate minimum digits required for Chef and Rick
        long long dc = (pc + 8) / 9;
        long long dr = (pr + 8) / 9;

        // Determine winner based on rules
        // If Chef's digits are strictly less than Rick's, Chef wins.
        // Otherwise, Rick wins (either because he has fewer digits or they are equal).
        if (dc < dr) {
            cout << "0 " << dc << "\n";
        } else {
            cout << "1 " << dr << "\n";
        }
    }

    return 0;
}