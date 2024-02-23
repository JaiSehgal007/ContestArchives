#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 

// Let's use the method of dynamic programming. Let dp[i][j][k]
//  be the minimum number of operations required for the distance from i
//  to the farthest unpainted cell on the left to be j
// , and to the nearest unpainted cell on the right to be k
//  (including itself).

// We will update the values forward, that is, for all reachable states, we will find the states reachable from it and update the answer for them. In this case, we will move from the current i
//  to i+1
// , recalculating j
//  and k
//  depending on the action: not spraying paint from i
// , spraying paint from i
//  to the left, spraying paint from i
//  to the right.

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn(i, n)
            cin >> a[i];
 
        vector<vector<vector<int>>> d(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX)));
        d[0][0][0] = 0;
 
        forn(i, n)
            forn(j, n)
                forn(k, n + 1)
                    if (d[i][j][k] < INT_MAX) {
                        int ai = a[i];
 
                        // Z
                        {
                            int ni = i + 1;
                            int nj = j > 0 ? j + 1 : (k == 0 ? 1 : 0);
                            int nk = max(0, k - 1);
                            d[ni][nj][nk] = min(d[ni][nj][nk], d[i][j][k]);
                        }
 
                        // L
                        {
                            int ni = i + 1;
                            int nj = j > 0 ? j + 1 : 0;
                            if (nj <= ai)nj = 0;
                            int nk = max(0, k - 1);
                            d[ni][nj][nk] = min(d[ni][nj][nk], d[i][j][k] + 1);
                        }
 
                        // R
                        {
                            int ni = i + 1;
                            int nj = j > 0 ? j + 1 : 0;
                            int nk = max(ai - 1, k - 1);
                            d[ni][nj][nk] = min(d[ni][nj][nk], d[i][j][k] + 1);
                        }
                    }
 
        cout << *min_element(d[n][0].begin(), d[n][0].end()) << endl;
    }
}


// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n);
//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//         }

//         vector<long long> dp(n + 1, 1e18);
//         dp[0] = 0;

//         for (int i = 0; i < n; i++) {
//             long long x = dp[i];
//             for (int j = i - 1; j >= 0; j--) {
//                 dp[j] = min(dp[j], dp[j + 1]);
//             }
//             dp[i + 1] = min(dp[i + 1], dp[max(0, i + 1 - a[i])] + 1);
            
//             for (int j = i + 1; j < min(n, i + a[i]); j++) {
//                 x = min(x, dp[min(i, max(0, j - a[j] + 1))] + 1);
//                 dp[j + 1] = min(dp[j + 1], x + 1);
//             }
//         }

//         cout << dp[n] << endl;
//     }

//     return 0;
// }
