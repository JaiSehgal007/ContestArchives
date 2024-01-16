// this technique is called square root technique
// two ideas, indivisually both will get TLE, but when we use them for different cases they will pass

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
#define eb emplace_back
#define Sort(nums) sort(nums.begin(),nums.end())
#define PQmin priority_queue<int,vi,gri>
#define PQmax priority_queue<int,vi>
using t3=array<int,3>;

int const Inf=1e9;
int const N=1e5+3;

const int R=360;

signed main()
{
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        vi a(n+1),res(q);
        rep(i,1,n+1)cin>>a[i];
        vector<vector<array<int,3>>>queries(min(n,R)+1);
        for(int i=0;i<q;i++){
            int s,d,k;cin>>s>>d>>k;

            if(d>R){
                int cur=0;
                for(int j=1;j<=k;j++){
                    cur+=j*a[s+(j-1)*d];
                }
                res[i]=cur;
                continue;
            }
            // inputting the starting and the ending value
            queries[d].eb(t3{s-d,s+d*(k-1),i});
        }

        for(int d=1;d<=n and d<=R;d++){
            const auto &v=queries[d];
            if(v.empty())continue;
            vii prefSum(n+1);
            for(int i=1;i<=n;i++){
                const int c=(i-1)/d+1;
                prefSum[i].ff=a[i];
                prefSum[i].ss=a[i]*c;
                if(i>=d){
                    prefSum[i].ff+=prefSum[i-d].ff;
                    prefSum[i].ss+=prefSum[i-d].ss;
                }
            }

            for(const auto &que:v){
                const int L=que[0],R=que[1],idx=que[2];
                int &cur=res[idx];
                cur+=prefSum[R].ss;
                if(L>0){
                    cur-=prefSum[L].ss;
                    const int c=(L-1)/d+1;
                    cur-=(prefSum[R].ff-prefSum[L].ff)*c;
                }
            }
        }
        for(int i=0;i<q;i++)cout<<res[i]<<" ";
        cout<<endl;

    }

    return 0;
}