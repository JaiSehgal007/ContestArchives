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
    int n,k;cin>>n>>k;
    vi a(n);
    // cout<<n<<" "<<k<<endl;
    set<int>s={1, 7, 17, 119, 289, 2023};
    int mul=1;
    rep(i,0,n){
        cin>>a[i];
        mul*=a[i];        
    }
    for(auto e:a)if(s.count(e)==0){
            cout<<"NO"<<endl;
            return;
        }
    int req=2023/mul;
    if(2023%mul!=0){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    for(int i=0;i<k-1;i++){
        cout<<1<<" ";
    }cout<<req<<endl;

      
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}