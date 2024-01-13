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

void solve(){
    int i,j,k,n;cin>>n;
    deque<int>que;
    for(int i=0;i<n;i++){
        ll z;cin>>z;
        que.push_back(z);
    }
    while(que.front()!=0){
        que.push_front(que.back());
        que.pop_back();
    }
    vector<int>a;
    while(que.size()){
        a.push_back(que.front());
        que.pop_front();
    }
    vector<ll>vals(n,n);
    stack<ll>s;
    vector<int>idx(n);
    s.push(0);
    for(int i=1;i<n;i++){
        while(s.size() and a[s.top()]>a[i])s.pop();
        idx[i]=s.top();
        s.push(i);
    }
    for(int i=1;i<n;i++){
        vals[i]=vals[idx[i]]+(i-idx[i])*a[i];
    }
    cout<<*max_element(begin(vals),end(vals))<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}