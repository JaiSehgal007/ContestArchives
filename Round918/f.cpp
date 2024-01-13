#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
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

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;

void solve(){
    int n,res=0;cin>>n;
    vvi a;
    ordered_set p;
    rep(i,0,n){
        int d,b;cin>>d>>b;
        a.pb({d,b});
        p.insert(b);
    }
    Sort(a);

    for(int i=0;i<n;i++){
        res+=p.order_of_key(a[i][1]);
        p.erase(p.lower_bound(a[i][1]));
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