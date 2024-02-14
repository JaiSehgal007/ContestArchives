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
#define PQmin priority_queue<int,vi,gri>
#define PQmax priority_queue<int,vi>
int const Inf=1e9;
int const N=1e5+3;

void solve(){
    ll n,k;cin>>n>>k;
    vector<ll>p(n+5);
    set<ll>track;
    for(ll i=1;i<=n;i++){
        p[i]=i-1;
        track.insert(i);
        k-=p[i];
    }
    if(k<=-1){
        cout<<"-1\n";
        return;
    }
    for(ll i=n;i>=2;i--){
        ll now=min(k,n-i);
        k-=now;
        p[i]+=now;
    }
    if(k!=0){
        cout<<"-1\n";
        return;
    }
    vector<ll>ans(n+5);
    auto op=[&](ll pos,ll val){
        if(!track.count(val)){
            val=*track.begin();
        }
        ans[pos]=val;
        track.erase(val);
    };
    for(ll i=1;i<=n;i++){
        op(i,p[i]+1);
        cout<<ans[i]<<" \n"[i==n];
    }

}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}