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
    int n;cin>>n;
    vi a(n);
    rep(i,0,a.size()){
        cin>>a[i];
    }
    int price=n-1;
    int l=1,r=n-2;
    
    for(;l<n;l++){
        if(a[l]!=a[l-1])break;
    }
    for(;r>=0;r--){
        if(a[r]!=a[r+1])break;
    }

    if(a[0]==a.back()){
        cout<<max(0LL,(ll)(r-l+1))<<endl;
    }
    else {
        // cout<<l<<" "<<r<<endl;
        cout<<min({n-l,r+1})<<endl;
    }

}
signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}