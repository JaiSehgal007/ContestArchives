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
        int n;cin>>n;
        vii a(n),b(n),c(n);
        rep(i,0,n){
            cin>>a[i].ff;
            a[i].ss=i;
        }
        rep(i,0,n){
            cin>>b[i].ff;
            b[i].ss=i;
        }
        rep(i,0,n){
            cin>>c[i].ff;
            c[i].ss=i;
        }

        sort(rbegin(a),rend(a));
        sort(rbegin(b),rend(b));
        sort(rbegin(c),rend(c));

        int ans=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(a[i].ss!=c[k].ss and a[i].ss!=b[j].ss and b[j].ss!=c[k].ss){
                        ans=max(ans,a[i].ff+b[j].ff+c[k].ff);
                    }
                }
            }
        }
        cout<<ans<<endl;
        
    }

    return 0;
}