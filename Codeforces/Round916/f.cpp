#include<bits/stdc++.h>
using namespace std;

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
int const N=5e5+10;

int t;
int n,ans;


void dfs1(int u,vvi &g,vi&siz){
    siz[u]=1;
    for(auto j:g[u]){
        dfs1(j,g,siz);
        siz[u]+=siz[j];
    }
}

int dfs(int u,int x,vvi &g,vi&siz){
    ans+=(x>0);
    if(x>0)x--;
    
    int tot=siz[u]-1;

    for(auto v:g[u]){
        dfs(v,x+tot-siz[v],g,siz);
    }
}

void solve(){
    cin>>n;
    vvi g;
    vi siz;
    g.resize(n+1);
    siz.resize(n+1,0);
    for(int i=2;i<=n;i++){
        int p;cin>>p;
        g[p].pb(i);
    }
    ans=0;
    dfs1(1,g,siz);
    dfs(1,0,g,siz);
    cout<<ans/2<<endl;
}

signed main()
{
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}