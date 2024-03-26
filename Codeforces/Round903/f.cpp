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
#define Sort(nums) sort(nums.rbegin(),nums.rend())
#define PQmin priority_queue<int,vi,gri>
#define PQmax priority_queue<int,vi>
int const Inf=1e9;
int const N=1e5+3;

int dfs(int cur,int par,ump&marked,vector<vvi>&list,vvi&adj){
    vvi tmp;
    for(auto nei:adj[cur]){
        if(nei!=par){
            int res=dfs(nei,cur,marked,list,adj);
            if(res!=INT_MAX){
                tmp.push_back({res,nei});
            }
        }
    }
    Sort(tmp);
    list[cur]=tmp;
    if(tmp.size()>0){
        return tmp[0][0]+1;
    }else{
        if(marked[cur])return 1;
        else return INT_MAX;
    }
}

void dfs1(int cur,int par,int parDist,ump&marked,int &res,vector<vvi>&list,vvi&adj){
    int dis=parDist;

    if(list[cur].size()){
        dis=max(dis,list[cur][0][0]);
    }

    if(dis>0)res=min(res,dis);

    int pass=dis+1;

    for(auto nei:adj[cur]){
        if(nei!=par){
            if(pass!=parDist+1 and list[cur].size() and nei==list[cur][0][1]){
                dis=parDist+1;
                if(list[cur].size()>1){
                    dis=max(dis,list[cur][1][0]+1);
                }
                if(dis<0 and marked[cur])dis=1;
                dfs1(nei,cur,dis,marked,res,list,adj);
            }
            else dfs1(nei,cur,pass,marked,res,list,adj);
        }
    }
}


signed main()
{
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        ump marked;
        rep(i,0,k){
            int a;cin>>a;
            marked[a-1]++;
        }

        vvi adj(n);
        for(int i=0;i<n-1;i++){
            int x,y;cin>>x>>y;
            x--;y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        if(k==1){
            cout<<0<<endl;
            continue;
        }

        vector<vvi>list(n);

        dfs(0,-1,marked,list,adj);

        int res=INT_MAX;
        dfs1(0,-1,INT_MIN,marked,res,list,adj); 
        cout<<res<<endl;       
    }

    return 0;
}