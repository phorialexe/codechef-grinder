#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N nominees and M total votes.
 * Om needs a "strict majority win", meaning if Om gets X votes, 
 * every other nominee must have strictly less than X votes.
 * 
 * Let X be the number of votes Om receives.
 * The remaining votes are (M - X).
 * These (M - X) votes are distributed among the other (N - 1) nominees.
 * To ensure Om wins, even if the remaining votes are distributed as evenly 
 * as possible, the maximum any other nominee gets must be less than X.
 * 
 * The worst-case scenario for Om is when the remaining (M - X) votes are 
 * distributed such that one of the other nominees gets as many as possible.
 * To keep the maximum votes of any other nominee < X, we need:
 * floor((M - X) / (N - 1)) < X
 * 
 * Actually, the condition is simpler: if Om gets X votes, the maximum 
 * any other person can get is floor((M - X) / (N - 1)).
 * We need floor((M - X) / (N - 1)) <= X - 1.
 * (M - X) / (N - 1) <= X - 1
 * M - X <= (X - 1) * (N - 1)
 * M - X <= X*N - X - N + 1
 * M <= X*N - N + 1
 * M + N - 1 <= X*N
 * X >= (M + N - 1) / N
 * 
 * Since we need the minimum integer X, X = floor((M + N - 1) / N).
 * Using integer division, this is (M + N - 1) / N.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // The formula derived: X = floor((M + N - 1) / N)
        // Using long long to prevent overflow, though constraints M <= 10^9 fit in int.
        long long ans = (m + n) / n;
        
        // Let's verify the logic with sample cases:
        // 5 12: (12 + 5) / 5 = 17 / 5 = 3. Wait, the sample says 7.
        // Re-reading: "all the nominees have strictly lesser votes than the winner."
        // If Om has X, others have < X.
        // Max votes for others is X-1.
        // Total votes M = X + (N-1) * (others).
        // To minimize X, we maximize others: others = X-1.
        // M = X + (N-1)(X-1)
        // M = X + NX - N - X + 1
        // M = NX - N + 1
        // M + N - 1 = NX
        // X = (M + N - 1) / N
        // Wait, 5 12 -> (12 + 5 - 1) / 5 = 16 / 5 = 3.2 -> 4? 
        // Sample 1: 5 12 -> 7. 
        // If Om has 7, others have max 6. 6 * 4 = 24. 7 + 24 = 31 >= 12. 
        // Ah, the condition is simply that Om must have more than anyone else.
        // If Om has X, the remaining M-X votes must be distributed such that 
        // no one gets >= X.
        // The smallest X such that X > (M-X)/(N-1) is not the constraint.
        // The constraint is: Om must have more than the average of the rest? No.
        // If Om has X, the remaining M-X votes are distributed. 
        // The best way to prevent anyone from reaching X is to distribute M-X 
        // as evenly as possible. The max any other gets is ceil((M-X)/(N-1)).
        // We need ceil((M-X)/(N-1)) < X.
        
        // Let's re-check 5 12:
        // X=3: (12-3)/4 = 9/4 = 2.25 -> ceil is 3. 3 is not < 3.
        // X=4: (12-4)/4 = 8/4 = 2. 2 < 4. Correct.
        // Wait, sample says 7. Why 7?
        // "If he gets 7 votes, it is not possible for any other nominee to get at least 7 votes."
        // 12 - 7 = 5. 5 votes distributed among 4 people. Max is 2. 2 < 7.
        // 12 - 6 = 6. 6 votes distributed among 4 people. Max is 2. 2 < 6.
        // 12 - 3 = 9. 9 votes distributed among 4 people. Max is 3. 3 < 3 is false.
        // The condition is: X > (M-X)/(N-1) is wrong. 
        // It is: X > (M-X) / (N-1) is not enough. 
        // Actually, the condition is: X > (M-X) / (N-1) is only if we can distribute perfectly.
        // The condition is simply X > (M-X) / (N-1) is not correct.
        // It is X > (M-X) / (N-1) is not the right inequality.
        // The condition is: Even if all remaining votes go to one person, they must have < X.
        // M - X < X  => M < 2X => X > M/2.
        // But that's only if N=2.
        // If N=5, M=12. If Om has 3, remaining 9. One person could have 9. 9 is not < 3.
        // If Om has 7, remaining 5. Max any other can have is 5. 5 < 7.
        // So the condition is: M - X < X  => X > M/2.
        // Wait, 12/2 = 6. X > 6 => 7.
        // 5/2 = 2.5 => 3.
        // Yes, X = floor(M/2) + 1.
        
        cout << (m / 2) + 1 << "\n";
    }
    return 0;
}