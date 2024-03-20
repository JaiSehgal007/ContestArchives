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
        int n,m;cin>>n>>m;
        vi a(n),b(n);
        rep(i,0,a.size()){
            cin>>a[i];
        }
        rep(i,0,b.size()){
            cin>>b[i];
        }
        reverse(begin(a),end(a));
        reverse(begin(b),end(b));

        int prevSum=0;
        for(int i=0;i<n-m;i++){
            prevSum+=min(a[i],b[i]);
        }

        for(int i=1;i<n;i++){
            b[i]+=b[i-1];
        }

        int res=INT_MAX;
        for(int i=max(n-m,0LL);i<n;i++){
            int prev=((n-m-1)<0)?0:b[n-m-1];
            if(i!=0)res=min(res,(b[i-1]-prev)+a[i]);
            else res=min(res,a[i]);
        }

        cout<<res+prevSum<<endl;       
    }

    return 0;
}