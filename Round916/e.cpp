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

int solve(){
    int n;cin>>n;
    vii a(n);
    rep(i,0,n)cin>>a[i].ff;
    rep(i,0,n)cin>>a[i].ss;

    sort(begin(a),end(a),[&](pii a,pii b){
        return (a.ff+a.ss)>(b.ff+b.ss);
    });

    int ans=0;
    rep(i,0,n){
        if(i%2==0)a[i].first--,a[i].second=0;
		else a[i].second--,a[i].first=0;
		ans+=a[i].first-a[i].second;
    }
    return ans;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}