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
        int n,m;cin>>n>>m;
        string x,s;cin>>x>>s;

        int op=0;
        while(x.size()<s.size()){
            x+=x;
            op++;
        }

        int pos=x.find(s);
        if(pos!=string::npos){
            cout<<op<<endl;
        }else{
            op++;
            x+=x;
            int pos=x.find(s);
            if(pos!=string::npos){
                cout<<op<<endl;
            }else{
                cout<<-1<<endl;
            }
        }
    }

    return 0;
}