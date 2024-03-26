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

int findRem(int idx,vi &a,vi&dp){
    if(idx==a.size())return 0;
    if(idx>a.size())return INT_MAX;
    if(dp[idx]!=-1)return dp[idx];

    int keep=findRem(idx+a[idx]+1,a,dp);
    int drop=1+findRem(idx+1,a,dp);

    return dp[idx]=min(drop,keep);
}

signed main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi a(n);
        rep(i,0,a.size()){
            cin>>a[i];
        }
        vi dp(n,-1);
        cout<<findRem(0,a,dp)<<endl;
    }

    return 0;
}