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
    int a,b;cin>>a>>b;
    int kx,ky;cin>>kx>>ky;
    int qx,qy;cin>>qx>>qy;

    set<vector<int>>s,res;

    // assuming king and queen as knight finding the common coordinates
    vector<vector<int>>dirs={{a,b},{b,a},{-a,-b},{-b,-a},{-a,b},{-b,a},{a,-b},{b,-a}};

    for(auto d:dirs){
        s.insert({kx+d[0],ky+d[1]});
    }
   
    for(auto d:dirs){
        if(s.count({qx+d[0],qy+d[1]})!=0){
            res.insert({qx+d[0],qy+d[1]});
        }
    }

    cout<<res.size()<<endl;

}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}