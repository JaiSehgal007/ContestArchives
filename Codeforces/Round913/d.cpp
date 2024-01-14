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

bool isPoss(vvi &seg,int k){
    ll left=0,right=0;
    for(ll i=0;i<seg.size();i++){
        if(right+k<seg[i][0] || seg[i][1]<left-k){
            return false;
        }
        right=min(right+k,seg[i][1]);
        left=max(left-k,seg[i][0]);
    }
    return true;
}

signed main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vvi seg;
        int mmax=0;
        rep(i,0,n){
            int a,b;cin>>a>>b;
            seg.pb({a,b});
            mmax=max({mmax,a,b});
        }
        
        int lo=0,hi=mmax;
        int res=hi;
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(isPoss(seg,mid)){
                res=min(res,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        cout<<res<<endl;
    }

    return 0;
}