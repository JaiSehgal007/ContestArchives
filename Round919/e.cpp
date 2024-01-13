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
int mod=998244353;

signed main()
{
    int t;cin>>t;

    while(t--){
        int n,k;cin>>n>>k;

        int dp[n+1][k+1]={};
        int ans=0;

        fill(dp[0]+1,dp[0]+k+1,1);
        for(int sum=1;sum<=n;sum++){
            for(int cur=1;cur<=k;cur++){
                for(int prv=1;cur*prv<=sum and cur+prv-1<=k;prv++){
                    dp[sum][cur]=(dp[sum][cur]+dp[sum-cur*prv][prv])%mod;
                }
                if(sum==n){
                    ans=(ans+dp[sum][cur])%mod;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}