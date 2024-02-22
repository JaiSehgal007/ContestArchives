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
        int a,b,r,x=0,first_bit=1;cin>>a>>b>>r;
        if(b>a)swap(b,a);
        for(int i=59;i>=0;i--){
            bool ab=(a>>i)&1ll;
            bool bb=(b>>i)&1ll;
            if(ab!=bb){
                if(first_bit)first_bit=0;
                else if(bb==0 and (x+(1ll<<i))<=r){
                    x+=(1ll<<i);
                    a^=(1ll<<i);
                    b^=(1ll<<i);
                }
            }
        }
        cout<<a-b<<endl;
    }

    return 0;
}