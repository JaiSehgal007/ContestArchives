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
        int n;cin>>n;
        vvi a(n,vi(2));
        rep(i,0,a.size()){
            cin>>a[i][0];
        }
        rep(i,0,a.size()){
            cin>>a[i][1];
        }
        sort(begin(a),end(a));
        for(auto e:a)cout<<e[0]<<" ";
        cout<<endl;for(auto e:a)cout<<e[1]<<" ";
        cout<<endl;        
    }

    return 0;
}