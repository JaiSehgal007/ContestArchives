#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<long long>
#define vvi vector<vector<long long>>
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
    vvi mat(n,vi(n,0));
    rep(i,0,n){
        rep(j,0,n){
            cin>>mat[i][j];
        }
    }
    vi res(n);
    for(int i=0;i<n;i++){
        int ans=1073741823;
        for(int j=0;j<n;j++){
            if(i!=j)ans=ans&mat[i][j];
            if(i!=j)ans=ans&mat[j][i];
        }
        res[i]=ans;
    }
    rep(i,0,n){
        rep(j,0,n){
            if(i!=j and mat[i][j]!=(res[i]|res[j])){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    rep(i,0,n)cout<<res[i]<<" ";
    cout<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}