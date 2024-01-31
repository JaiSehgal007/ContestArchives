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
        int n,q;cin>>n>>q;
        string s;cin>>s;
        vi res(q+1);

        rep(i,0,q){
            char c;
            cin>>c;
            s+=c;
        }

        int mx = 1;
        int c = 1;
        rep(i,1,n){
            if(s[i]==s[i-1]){
                c++;
            }
            else c = 1;
            if(c>mx){
                mx = c;
            }
        }
        
        res[0]=mx;

        rep(i,n,s.size()){
            if(s[i]==s[i-1]){
                c++;
            }
            else c = 1;
            if(c>mx){
                mx = c;
            }
            res[i-n+1]=mx;
        }

        rep(i,0,q+1){
            cout<<res[i]<<" ";
        }cout<<endl;
          
    }

    return 0;
}