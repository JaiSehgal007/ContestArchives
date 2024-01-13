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

long long solve(){
    long long a,b;cin>>a>>b;
    if(a==1 || b==1){
        return a*a*b*b;
    }else{
        int gc=__gcd(a,b);
        int da=a/gc;
        int db=b/gc;
        int ret = da*db*gc;
        
        if(ret==b){
            return ret*(b/a);
        }else{
            return ret;
        }
    }
}

signed main()
{
    int t;cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }

    return 0;
}