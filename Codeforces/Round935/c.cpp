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

void solve()
{
    int n, rs = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            rs++;
    }
    int ls = 0;
    int res=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (rs >= ((n - i + 1) / 2) and ls >= (i + 1) / 2)
        {
            if(abs(((float)n/2)-i) < abs(((float)n/2)-res))res=i;        
        }
        if (s[i] == '0')
            ls++;
        else
            rs--;
    }
    if (rs >= ((n - n + 1) / 2) and ls >= (n + 1) / 2)
    {
        if(abs(((float)n/2)-n) < abs(((float)n/2)-res))res=n;
    }
    cout<<res<<endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}