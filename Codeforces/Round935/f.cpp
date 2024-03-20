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
        vi a(n+1),p(n+1,0);
        
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>p[i];

        priority_queue<int,vector<int>,greater<int>>pq;
        ll product=0;
        int elements=0;
        for(int i=n;i>0;i--){
            pq.push(a[p[i]]);
            while(pq.size()>i){
                pq.pop();
            }
            if(pq.size()==i){
                if(product<=1ll*i*pq.top()){
                    product=1ll*i*pq.top();
                    elements=i;
                }
            }
        }
        cout<<product<<" "<<elements<<endl;
    }

    return 0;
}