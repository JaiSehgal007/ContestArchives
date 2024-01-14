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

const int MAXN = 200005;

int n;
int a[MAXN];
int prv[MAXN],nxt[MAXN];
bool in[MAXN];

bool good(int i){
    if(i<1 || i>n)return 0;
    return a[prv[i]]==a[i]-1 || a[nxt[i]]==a[i]-1;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        cin>>n;
        priority_queue<pii>pq;
        for(int i=1;i<=n;i++){
            prv[i]=i-1;
            nxt[i]=i+1;
            in[i]=0;
            cin>>a[i];
        }
        a[n+1]=a[0]=-2;

        for(int i=1;i<=n;i++){
            if(good(i)){
                in[i]=1;
                pq.push({a[i],i});
            }
        }

        while(pq.size()){
            auto [_,i]=pq.top();pq.pop();
            nxt[prv[i]]=nxt[i];
            prv[nxt[i]]=prv[i];
            if(!in[prv[i]] and good(prv[i])){
                in[prv[i]]=1;
                pq.push({a[prv[i]],prv[i]});
            }
            if(!in[nxt[i]] and good(nxt[i])){
                in[nxt[i]]=1;
                pq.push({a[nxt[i]],nxt[i]});
            }
        }
        int mn=n,bad=0;
        for(int i=1;i<=n;i++){
            bad+=!in[i];
            mn=min(mn,a[i]);
        }
        if(bad==1 and mn==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}