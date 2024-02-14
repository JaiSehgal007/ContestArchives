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

void solve(){
    int n,x,y;cin>>n>>x>>y;
    vi a(n);
    rep(i,0,a.size()){
        cin>>a[i];
    }
    sort(begin(a),end(a));
    unordered_map<int,vector<int>>m;
    for(auto e:a){
        m[e%y].push_back(e);
    }

    int res=0;
    for(auto e:m){
        auto ar=e.second;
        unordered_map<int,int>mp;
        for(auto &f:ar){
            mp[f%x]++;
            f%=x;
        }
        for(auto &f:ar){
            mp[f]--;
            res+=mp[(x-f)%x];
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