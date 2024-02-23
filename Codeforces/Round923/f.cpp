// F. Microcycle
/*
Given an undirected weighted graph with n vertices and m edges. There is at most one edge between each pair of vertices in the graph, and the graph does not contain loops (edges from a vertex to itself). The graph is not necessarily connected.
A cycle in the graph is called simple if it doesn't pass through the same vertex twice and doesn't contain the same edge twice.
Find any simple cycle in this graph in which the weight of the lightest edge is minimal.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb emplace_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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
#define Sort(nums) sort(nums.begin(),nums.end())
#define PQmin priority_queue<int,vi,gri>
#define PQmax priority_queue<int,vi>
int const Inf=1e9;
int const N=1e5+3;

struct dsu{
    vector<int>p,lvl;

    dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
        lvl.assign(n,0);
    }

    int get(int i){
        if(p[i]==i)return i;
        return p[i]=get(p[i]);
    }

    bool unite(int a,int b){
        a=get(a);
        b=get(b);
        if(a==b)return false;
        if(lvl[a]<lvl[b])swap(a,b);
        p[b]=a;
        if(lvl[a]==lvl[b])lvl[a]++;
        return true;
    }
};



bool found;
vector<int> ans, path;

void dfs(int v,int p,vector<vector<int>>&g,int f){
    path.push_back(v);
    if(v==f){
        ans=path;
        found=true;
        return;
    }

    for(int u:g[v]){
        if(u!=p)dfs(u,v,g,f);
        if(found)return;
    }
    path.pop_back();
}

void solve(){
    int n,m;cin>>n>>m;
    vvi sl(n);
    vector<pair<int,pair<int,int>>>edges;
    for(auto i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        u--;v--;
        edges.push_back({w,{u,v}});
    }
    sort(rall(edges));
    dsu g(n);
    pair<int,int>fin;
    int best=INT_MAX;
    for(auto e:edges){
        if(!g.unite(e.y.x,e.y.y)){
            fin=e.y;
            best=e.x;
        }else{
            sl[e.y.x].push_back(e.y.y);
            sl[e.y.y].push_back(e.y.x);
        }
    }
    found=false;
    path.resize(0);
    dfs(fin.x,-1,sl,fin.y);
    cout<<best<<" "<<ans.size()<<endl;
    for(auto e:ans)cout<<e+1<<" ";
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }

    return 0;
}