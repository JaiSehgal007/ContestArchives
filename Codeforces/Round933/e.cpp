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
        int n,m,k,d;
        cin>>n>>m>>k>>d;

        vvi a(n+1,vi(m+1));
        rep(i,1,n+1){
            rep(j,1,m+1){
                cin>>a[i][j];
            }
        }

        vector<int>cost(n+1);

        for(int i=1;i<=n;i++){
            deque<pair<ll,ll>>dq;
            dq.pb({1,1});
            for(int j=2;j<=m;j++){
                while(dq.front().first < j-d-1)dq.pop_front();
                while(dq.back().second >= (dq.front().second + a[i][j] +1)){
                    dq.pop_back();
                }
                dq.push_back({j,dq.front().second+a[i][j]+1});
                if(j==m)cost[i]=dq.back().second;
            }
        }

        for(int i=1;i<=n;i++)cost[i]+=cost[i-1];

        ll ans=LLONG_MAX;
        for(int i=k;i<=n;i++)ans=min(ans,cost[i]-cost[i-k]);
        cout<<ans<<endl;
    }

    return 0;
}