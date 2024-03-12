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
const int MOD = 998244353;
const int INF = 1e9 + 7;
const int MX = 200005;
 
int n, m, k;

signed main()
{
    int t;cin>>t;
    while(t--){
        cin>>n>>m>>k;
        vector<int> a(n), d(m), f(k);
        rep(i,0,n)cin>>a[i];
        rep(i,0,m)cin>>d[i];
        rep(i,0,k)cin>>f[i];

        int rlt=0,rlt1=0,cnt=0,id=-1;

        Sort(a);Sort(d);Sort(f);

        rep(i,1,n)rlt=max(rlt,a[i]-a[i-1]);
        rep(i,1,n)if((a[i]-a[i-1]) == rlt)cnt++;
        
        if(cnt>1){
            cout<<rlt<<endl;
            continue;
        }

        rep(i,1,n)if(rlt==a[i]-a[i-1])id=i-1;
        rep(i,1,n)if(rlt!=a[i]-a[i-1])rlt1=max(rlt1,a[i]-a[i-1]);

        int md=(1LL*a[id+1] + 1LL*a[id])/2;


        rep(i,0,m){
            int num = lower_bound(begin(f),end(f),md-d[i])-begin(f);
            if(num<k and a[id+1]>d[i]+f[num])rlt = min(rlt, max(d[i] + f[num] - a[id], a[id + 1] - f[num] - d[i]));
            num--;
            if(num>=0 and num<k and  a[id+1]>d[i]+f[num])rlt = min(rlt, max(d[i] + f[num] - a[id], a[id + 1] - f[num] - d[i]));
        }

        cout<<max(rlt,rlt1)<<endl;
    }

    return 0;
}