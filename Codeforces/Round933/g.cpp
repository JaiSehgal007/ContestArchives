// A Very Nice Implementation & Use case of Bipartitie Graph

// Problem Statement
// Building bridges did not help Bernard, and he continued to be late everywhere. 
// Then Rudolf decided to teach him how to use the subway.

// Rudolf depicted the subway map as an undirected connected graph, without self-loops, 
// where the vertices represent stations. There is at most one edge between any pair of 
// vertices.

// Two vertices are connected by an edge if it is possible to travel directly between the 
// corresponding stations, bypassing other stations. The subway in the city where Rudolf 
// and Bernard live has a color notation. This means that any edge between stations has 
// a specific color. Edges of a specific color together form a subway line. A subway line 
// cannot contain unconnected edges and forms a connected subgraph of the given subway graph

// Rudolf claims that the route will be optimal if it passes through the minimum number of 
// subway lines.

// Help Bernard determine this minimum number for the given departure and destination 
// stations.



// Intution
// Let's construct a bipartite graph, where one part is the vertices of the original 
// graph, i.e., subway stations, and the other part is the subway lines. We add an 
// edge between a station vertex and a line vertex if in the original subway graph, 
// the station is incident to an edge of the corresponding subway line. In the new graph, 
// we find the shortest path between the vertices corresponding to the departure and 
// destination stations (for example, using breadth-first search). The answer to the 
// problem will be the shortest path, divided in half.


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

signed main()
{
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;

        vector<vii>g(n+1);
        ump clrs;
        int idx=n+1;

        for(int i=0;i<m;i++){
            int u,v,c;cin>>u>>v>>c;
            g[u].pb({v,c});
            g[v].pb({u,c});
            if(!clrs.count(c)){
                clrs[c]=idx++;
            }
        }

        int s,t;cin>>s>>t;

        if(s==t){
            cout<<0<<endl;
            continue;
        }

        vector<set<int>>bg(n+clrs.size()+3);

        for(int i=1;i<n;i++){
            for(auto &[to,c] : g[i]){
                int clr_v=clrs[c];
                bg[i].insert(clr_v);
                bg[clr_v].insert(i);
                bg[clr_v].insert(to);
                bg[to].insert(clr_v);
            }
        }

        vi used(bg.size());
        vi d(bg.size(),-1);

        auto bfs=[&](int v){
            queue<int>q;
            q.push(v);
            used[v]=1;
            d[v]=0;
            while(q.size()){
                auto from=q.front();
                q.pop();
                for(auto &to:bg[from]){
                    if(!used[to]){
                        q.push(to);
                        used[to]=1;
                        d[to]=d[from]+1;
                    }
                }
            }
        };

        bfs(s);

        if(d[t]>0)cout<<d[t]/2<<endl;
        else cout<<-1<<endl;

    }

    return 0;
}