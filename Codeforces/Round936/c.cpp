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

int dfs(int cur,int par,int num,int &res,vvi &adj){
    int sum=0;
    for(auto nei:adj[cur]){
        if(nei!=par){
            int sub=dfs(nei,cur,num,res,adj);
            if(sub>=num){
                res++;
            }else{
                sum+=sub;
            }
        }
    }
    return sum+1;
}


void solve(){
    int n,k;cin>>n>>k;
    vvi adj(n);

    rep(i,0,n-1){
        int a,b;cin>>a>>b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int maxx=n%(k+1)==0?n/(k+1):(n/(k+1))+1;

    int lo=1,res=1;

    while(lo<=maxx){
        int mid=(lo+maxx)/2,tmp=0;
        int ret=dfs(0,-1,mid,tmp,adj);
        if(ret<mid)tmp--;

        if(tmp>=k){
            res=mid;
            lo=mid+1;
        }else{
            maxx=mid-1;
        }
    }

    cout<<res<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}