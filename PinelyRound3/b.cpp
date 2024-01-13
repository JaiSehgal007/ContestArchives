// ONE IMPORTANT THING TO NOTICE IN THIS QUESTION IS THAT
// LIKE WHEN WE DIVIDE WE ARE LEFT WITH THE LEFT BITS
// SIMILARY WHEN WE DO MODULUS WE GET THE RIGHT BITS OF THE NUMBER


#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<long long>
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
    
    ll k=1;
    while(true){
        set<int>s;
        for(int i=0;i<n;i++)s.insert(a[i]%k);
        if(s.size()==2){
            cout<<k<<endl;
            return;
        }
        k*=2LL;
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