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
        string a,b,c;cin>>a>>b>>c;

        int fl=0;
        for(int i=0;i<n;i++){
            if(a[i]==b[i] and a[i]!=c[i])fl=1;
            else if(c[i]!=b[i] and c[i]!=a[i])fl=1;
        }

        if(fl==0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}