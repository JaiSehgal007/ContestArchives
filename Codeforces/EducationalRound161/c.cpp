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
        vi a(n);
        rep(i,0,a.size()){
            cin>>a[i];
        }
        int m;cin>>m;
        vvi que;
        rep(i,0,m){
            int j,k;cin>>j>>k;
            j--;k--;
            que.push_back({j,k});
        }

        vi dis(n),bdis(n);
        dis[0]=0;
        dis[1]=1;
        for(int i=2;i<n;i++){
            if((a[i]-a[i-1])>(a[i-1]-a[i-2])){
                dis[i]=dis[i-1]+(a[i]-a[i-1]);
            }else{
                dis[i]=dis[i-1]+1;
            }
        }

        bdis.back()=0;
        bdis[n-2]=1;



        for(int i=n-3;i>=0;i--){
            if((a[i+1]-a[i])>(a[i+2]-a[i+1])){
                bdis[i]=bdis[i+1]+a[i+1]-a[i];
            }else{
                bdis[i]=bdis[i+1]+1;
            }
        }
        
        vi res;
        for(int i=0;i<m;i++){
            if(que[i][0]-que[i][1]<0){
                res.push_back(dis[que[i][1]]-dis[que[i][0]]);
            }else{
                res.push_back(bdis[que[i][1]]-bdis[que[i][0]]);
            }
        }
        for(auto e:res)cout<<e<<endl;
    }

    return 0;
}