#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>b;i--)
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

void solveN2(){
    // trick is to propogate the smaller vales first and then the larger values
    // simple o(N^2 way)
    int n;cin>>n;
    vi a(n),b(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];

    vvi c;
    rep(i,0,n)c.pb({a[i],i});
    Sort(c);

    for (auto e : c) {
        int x=e[0],i=e[1];

        rep(j,i,n){
            if(a[j]>x or b[j]<x)break;
            a[j]=x;
        }
        repr(j,i,-1){
            if(a[j]>x or b[j]<x)break;
            a[j]=x;
        }
    }

    if(a==b)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

void solve(){
    int n;cin>>n;
    vi a(n),b(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];

    for(int k=0;k<2;k++){
        deque<int>dq;
        rep(i,0,n){
            while(dq.size() and dq.back()<=a[i])dq.pop_back();
            while(dq.size() and dq[0]>b[i])dq.pop_front();
            dq.push_back(a[i]);
            if(dq[0]==b[i])a[i]=b[i];
        }
        reverse(begin(a),end(a));
        reverse(begin(b),end(b));
    }

    if(a==b)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        // solveN2();
        solve();
    }

    return 0;
}