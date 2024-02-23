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
        int n,k;cin>>n>>k;
        int l=1,r=n;
        vi ans(n);
        for(int i=0;i<k;i++){
            for(int j=i;j<n;j+=k){
                if(i%2==0){
                    ans[j]=l;
                    l+=1;
                }else{
                    ans[j]=r;
                    r-=1;
                }
            }
        }
        rep(i,0,n){
            cout<<ans[i]<<" ";
        }cout<<endl;
    }

    return 0;
}