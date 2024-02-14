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

int fun(int x){
    if(x%10)return 0;
    return 1+fun(x/10);
}

void solve(){
    int n,m;cin>>n>>m;
    vi a(n),vec(n);
    int cnt=0;
    rep(i,0,n){
        cin>>a[i];
        vec[i]=fun(a[i]);
        cnt+=to_string(a[i]).length();
    }
    sort(rbegin(vec),rend(vec));
    for(int i=0;i<n;i+=2){
        cnt-=vec[i];
    }
    if(cnt<=m)cout<<"Anna"<<endl;
    else cout<<"Sasha"<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}