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
const int LIM=1e5+7;

ll P[LIM],T[LIM],n,k;

void solve(){
    rep(i,0,n)T[i]=P[i];

    ll ans=0;

    for(ll i=60;i>=0;i--){
        ll sum=0;
        rep(j,0,n){
            if(T[j]&(1ll<<i))continue;
            ll p=(T[j]/(1ll<<i))*(1ll<<i)+(1ll<<i);
            p+=ans^(p&ans);
            sum+=p-T[j];
            if(sum>k)break;
        }
        if(sum>k)continue;
        rep(j,0,n){
            if(T[j]&(1ll<<i))continue;
            ll p=(T[j]/(1ll<<i))*(1ll<<i)+(1ll<<i);
            p+=ans^(p&ans);
            T[j]=p;
        }
        ans+=1ll<<i;
        k-=sum;
    }
    cout<<ans<<endl;
}

signed main()
{
    int q;
    cin>>n>>q;
    rep(i,0,n)cin>>P[i];
    while(q--){
        cin>>k;
        solve();
    }

    return 0;
}