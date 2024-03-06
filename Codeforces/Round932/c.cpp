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
        int n,L;cin>>n>>L;
        vii v(n);
        rep(i,0,n){
            cin>>v[i].ss>>v[i].ff;
        }
        Sort(v);
        int ans=0;

        rep(l,0,n){
            multiset<int>s;
            int cur=0;
            rep(r,l,n){
                s.insert(v[r].ss);
                cur+=v[r].ss;
                while(s.size() and v[r].ff-v[l].ff+cur>L){
                    int max_value=*s.rbegin();
                    cur-=max_value;
                    s.erase(s.lower_bound(max_value));
                }
                ans=max(ans,(int)s.size());
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}