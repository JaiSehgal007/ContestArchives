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
        string res="zzzz";
        for(int i=1;i<27;i++){
            for(int j=1;j<27;j++){
                int k=n-i-j;
                if(k<27){
                    char a='a'+i-1;
                    char b='a'+j-1;
                    char c='a'+k-1;
                    string s="";
                    s+=a;s+=b;s+=c;
                    cout<<s<<endl;
                    return;
                }
            }
        }
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}