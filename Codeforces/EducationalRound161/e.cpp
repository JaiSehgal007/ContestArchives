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

vi f(long long x){
    vi res;
    if(x==2){
        res.push_back(0);
    }else if(x&1){
        res=f(x-1);
        res.pb(*min_element(begin(res),end(res))-1);
    }else{
        res=f(x/2);
        res.push_back(*max_element(begin(res),end(res))+1);
    }
    return res;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        auto ans= f(n);
        cout<<ans.size()<<endl;
        for(auto e:ans)cout<<e<<" ";
        cout<<endl;
    }

    return 0;
}