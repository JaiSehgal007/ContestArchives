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
        int n,k,d;cin>>n>>k>>d;
        vi a(n);
        rep(i,0,a.size()){
            cin>>a[i];
        }
        vi b(k);
        rep(i,0,b.size()){
            cin>>b[i];
        }

        int ans=0;
        for(int i=0;i<d and i<=(2*n);i++){
            int cur=0;
            for(int j=0;j<n;j++)cur+=(a[j]==(j+1));
            cur+=(d-i-1)/2;
            ans=max(ans,cur);
            for(int j=0;j<b[i%k];j++)a[j]++;
        }

        cout<<ans<<endl;       
    }

    return 0;
}