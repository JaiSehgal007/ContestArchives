#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) __builtin_popcount(x)
#define omp map<int,int>
#define ump unordered_map<int,int>
#define gri greater<int>
#define pb push_back
#define Sort(nums) sort(nums.begin(),nums.end())
#define Sortr(nums) sort(nums.rbegin(),nums.rend())
#define PQmin priority_queue<int,vi,gri>
#define PQmax priority_queue<int,vi>
int const Inf=1e9;
int const N=1e5+3;

void solve(){
    int n;cin>>n;
    vi l(n),c(n);
    set<int>r;
    rep(i,0,n)cin>>l[i];
    rep(i,0,n){
        int a;cin>>a;
        r.insert(a);
    }
    rep(i,0,n)cin>>c[i];

    Sortr(c);
    Sort(l);
    vi res;
    for(int i=l.size()-1;i>=0;i--){
        auto ele=r.upper_bound(l[i]);
        res.push_back(*ele-l[i]);
        r.erase(ele);
    }
    Sort(res);
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=(long long)((long long)c[i]*(long long)res[i]);
    }
    cout<<ans<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}