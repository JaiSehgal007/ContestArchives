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
        int n,k,x;cin>>n>>k>>x;
        vi a(n);
        rep(i,0,a.size()){
            cin>>a[i];
        }
        Sort(a);
        int ans=0;
        rep(i,0,n-x){
            ans+=a[i];
        }
        rep(i,n-x,n){
            ans-=a[i];
        }
        int pos=1;
        int res=ans;

        for(int i=n-1;i>=0,k>0;i--){
            ans+=a[i];
            int idx=n-x-pos;
            if(idx>=0){
                ans-=(2*a[idx]);
            }
            res=max(ans,res);
            k--;pos++;
        }

        cout<<res<<endl;

    }

    return 0;
}