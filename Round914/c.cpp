#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) __builtin_popcount(x)
#define omp map<int, int>
#define ump unordered_map<int, int>
#define gri greater<int>
#define pb push_back
#define Sort(nums) sort(nums.begin(), nums.end())
#define PQmin priority_queue<int, vi, gri>
#define PQmax priority_queue<int, vi>
int const Inf = 1e9;
int const N = 1e5 + 3;

int solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, a.size())
    {
        cin >> a[i];
    }
    Sort(a);
    int res = a[0];

    if (k == 0)
        return a[0];
    if (k >= 3)
        return 0;
    if (k == 1)
    {
        for (int i = 1; i < n; i++)
            res = min(res, a[i] - a[i - 1]);
        return res;
    }

    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int v = a[i] - a[j];
            res=min(res,v);
            int p = lower_bound(begin(a), end(a), v) - begin(a);
            if (p < n)
                res = min(res, a[p] - v);
            if (p > 0)
                res = min(res, v - a[p - 1]);
        }
    }

    return res;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }

    return 0;
}