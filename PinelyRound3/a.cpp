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
    vvi coor;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        coor.pb({a,b});
    }

    set<char>s;

    for(auto co:coor){
        if(co[0]>0)s.insert('U');
        if(co[0]<0)s.insert('D');
        if(co[1]>0)s.insert('L');
        if(co[1]<0)s.insert('R');
    }

    if(s.size()==4)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
} 