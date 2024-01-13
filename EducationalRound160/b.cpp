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
    string s,t;cin>>s;
    t=s;
    int zc(0),oc(0);
    for(auto i=0;i<s.size();i++){
        if(s[i]=='0'){
            t[i]='1';
            zc++;
        }else{
            t[i]='0';
            oc++;
        }
    }
    for(int i=0;i<s.size();i++){
        if(t[i]=='0')zc--;
        if(t[i]=='1')oc--;
        if(oc<0 || zc<0){
            cout<<s.size()-i<<endl;
            return;
        }
    }
    cout<<0<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}