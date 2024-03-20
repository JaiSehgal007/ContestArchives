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


void dfs(vvi &adj,vi&dis,vi&par,int u,int p){
    par[u]=p;
    for(auto nei:adj[u]){
        if(nei!=p){
            dis[nei]=dis[u]+1;
            dfs(adj,dis,par,nei,u);
        }
    }
}

signed main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vvi adj(n);
        rep(i,0,n-1){
            int u,v;
            cin>>u>>v;
            u--;v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vi dis(n),par(n);
        dis[0]=0;
        dfs(adj,dis,par,0,0);

        int r=0;
        for(int i=0;i<n;i++){
            if(dis[r]<dis[i])r=i;
        }

        dis[r]=0;
        dfs(adj,dis,par,r,r);
        int l=r;
        for(int i=0;i<n;i++){
            if(dis[l]<dis[i])l=i;
        }

        vi diameter;
        int u=l;
        while(u!=r){
            diameter.pb(u);
            u=par[u];
        }

        diameter.pb(r);

        string ans="";
        for(int i=0;i<n;i++)ans+='?';

        int red=0,blue=0;
        for(int i=(diameter.size()/2);i<diameter.size();i++){
            ans[diameter[i]]='B';
            blue++;
        }
        for(int i=0;i<(diameter.size()/2);i++){
            ans[diameter[i]]='R';
            red++;
        }

        for(int i=0;i<n;i++){
            if(ans[i]=='?'){
                if(red<blue){
                    ans[i]='R';
                    red++;
                }else{
                    ans[i]='B';
                    blue++;
                }
            }
        }
        cout<<ans<<endl;


    }

    return 0;
}