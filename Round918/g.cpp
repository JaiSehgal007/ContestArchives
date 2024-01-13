#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<long long>
#define vvi vector<vector<long long>>
#define ll long long
#define pii pair<long long,long long>
#define vii vector<pii>
#define rep(i,a,b) for(long long i=a;i<b;i++)
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
long long const inf=1e18;
int const N=1e5+3;

void solve(){
    int n,m;cin>>n>>m;

    vii adj[n];
    rep(i,0,m){
        int u,v,w;cin>>u>>v>>w;
        u--;v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vi s(n);
    rep(i,0,n)cin>>s[i];

    vvi dist(n,vi(1001,inf));
    vvi vis(n,vi(1001,0));

    dist[0][s[0]]=0;

    priority_queue<vi,vvi>q;
    q.push({0,0,s[0]});
    
    while(q.size()){
        int u=q.top()[1],k=q.top()[2];
        q.pop();

        if(vis[u][k] || dist[u][k]==inf)continue;

        vis[u][k]=true;

        for(auto x:adj[u]){
            int v=x.first,w=x.second;
            int c=min(s[v],k);
            if(dist[v][c]>dist[u][k]+1LL*w*k){
                dist[v][c]=dist[u][k]+1LL*w*k;
                q.push({-dist[v][c],v,c});
            }
        }
    }

    int ans=inf;
    rep(i,1,1001)ans=min(ans,dist[n-1][i]);
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