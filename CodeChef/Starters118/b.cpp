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

bool poss(int n,int k,vi &a){
    int st=0;int cur=0;
    for(int i=0;i<a.size();i++){
        cur+=a[i];
        if(cur>=k){
            st++;
            cur=0;
        }
    }
    if(st>=n)return true;
    return false;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vi a(n);
        rep(i,0,a.size()){
            cin>>a[i];
        }
        int lo=1,hi=n,ans;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(poss(mid,m,a)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}