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
        vi a(n),preM(n+1,0),posM(n+1,0);
        rep(i,0,a.size()){
            cin>>a[i];
        }

        set<int>s;
        int nf=0;
        for(int i=0;i<n;i++){
            s.insert(a[i]);
            if(nf==a[i]){
                while(s.count(nf)){
                    nf++;
                }
                preM[i]=nf;
            }else{
                preM[i]=nf;
            }
        }

        set<int>s1;
        nf=0;
        for(int i=n-1;i>=0;i--){
            s1.insert(a[i]);
            if(nf==a[i]){
                while(s1.count(nf)){
                    nf++;
                }
                posM[i]=nf;
            }else{
                posM[i]=nf;
            }
        }

        for(int i=0;i<n-1;i++){
            if(preM[i]==posM[i+1]){
                cout<<2<<endl;
                cout<<1<<" "<<i+1<<endl;
                cout<<i+2<<" "<<n<<endl;
                return;
            }
        }

        cout<<"-1"<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();                
    }

    return 0;
}