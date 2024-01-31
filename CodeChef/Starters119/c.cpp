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
        cout<<1<<" ";
        int e=2,o=3,l=1;

        for(int i=0;i<k-1;i++){
            if(i%2==0){
                l=e;
                cout<<e<<" ";
                e+=2;
            }else{
                l=o;
                cout<<o<<" ";
                o+=2;
            }
        }
        for(int i=k-1;i<n;i++){
            if(l%2==0){
                while(e<=n){
                    cout<<e<<" ";
                    e+=2;
                }
                while(o<=n){
                    cout<<o<<" ";
                    o+=2;
                }
            }else{
                while(o<=n){
                    cout<<o<<" ";
                    o+=2;
                }
                while(e<=n){
                    cout<<e<<" ";
                    e+=2;
                }
            }
        }
        cout<<endl;
    }

    return 0;
}