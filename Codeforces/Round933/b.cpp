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

bool solve(){
    int n;cin>>n;
    vi a(n);
    rep(i,0,a.size()){
        cin>>a[i];
    }
    for(int i=1;i<n-1;i++){
        int subs=max(a[i-1],0LL);
        a[i-1]=min(a[i-1],0LL);
        a[i]-=2*subs;
        a[i+1]-=subs;
    }
    for(auto e:a)if(e>0 || e<0)return false;
    return true;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        if(solve())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}