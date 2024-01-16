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
    int x,y,a,b,c,d;cin>>x>>y>>a>>b>>c>>d;
    vvi fa(x),fb(x);
    a--;b--;c--;d--;
    rep(i,a,x){
        fa[i]={max(0ll,b-i+a),min(y-1,b+i-a)};
    }
    for(int i=c,j=0;i>=0;i--,j++){
        fb[i]={max(0ll,d-j),min(y-1,d+j)};
    }

    for(int posa=a+1,posb=c;posa<=posb;posa++,posb--){
        if(posa==posb and fa[posa][0]<=fb[posb][0] and fa[posa][1]>=fb[posb][1]){
            cout<<"alice"<<endl;
            return;
        }
    }
    for(int posa=a+1,posb=c-1;posa<=posb;posa++,posb--){
        if(posa==posb and fa[posa][0]>=fb[posb][0] and fa[posa][1]<=fb[posb][1]){
            cout<<"bob"<<endl;
            return;
        }
    }
    cout<<"draw"<<endl;
}
signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}