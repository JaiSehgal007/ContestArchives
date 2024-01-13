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
    int n;cin>>n;
    vi a(n);
    rep(i,0,a.size()){
        cin>>a[i];
    }
    int odd=0,sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        odd+=(a[i]%2);
        if(i==0){
            cout<<sum<<" ";
        }else{
            if(odd==1){
                cout<<sum-1<<" ";
            }else if(odd==2){
                cout<<sum<<" ";
            }else{
                int red=odd/3;
                int tt=odd-red*3;
                if(tt==1)red++;
                cout<<sum-red<<" ";
            }
        }
        
    }
    cout<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}