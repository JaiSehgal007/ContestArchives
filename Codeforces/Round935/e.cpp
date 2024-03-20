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
        int n,x;cin>>n>>x;
        vi a(n+1);
        int posx=-1;
        rep(i,1,a.size()){
            cin>>a[i];
            if(a[i]==x)posx=i;
        }
        int l=1,r=n+1;
        while(r-l!=1){
            int m=(r+l)/2;
            if(a[m]<=x){
                l=m;
            }else{
                r=m;
            }
        }
        if(l==posx){
            cout<<0<<endl;
        }else{
            cout<<1<<endl<<l<<" "<<posx<<endl;
        }
    }

    return 0;
}