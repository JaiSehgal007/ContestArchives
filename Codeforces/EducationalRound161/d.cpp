#include<bits/stdc++.h>
using namespace std;

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
        
        vi a(n+2),d(n+2,INT_MAX);
        rep(i,1,n+1)cin>>a[i];
        rep(i,1,n+1)cin>>d[i];

        set<int>lft,cur;
        for(int i=0;i<n+2;i++){
            lft.insert(i);
            cur.insert(i);
        }

        rep(z,0,n){
            set<int> del,ncur;
            for(int i:cur){
                auto it =lft.find(i);
                if(it==lft.end())continue;
                int prv=*prev(it);
                int nxt=*next(it);
                if(a[prv]+a[nxt] > d[i]){
                    del.insert(i);
                    ncur.insert(prv);
                    ncur.insert(nxt);
                }
            }
            cout<<del.size()<<" ";
            for(auto it:del)lft.erase(it);
            cur=ncur;
        }
        cout<<endl;
        
    }

    return 0;
}