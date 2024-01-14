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
    ll x;cin>>x;
    string s,l,t;
    cin>>s;
    t=s;
    Sort(t);
    if(s==t){
        cout<<"0"<<endl;
        return;
    }
    l="";
    vector<ll>v;
    map<char,ll>m1;
    ll ch=0;
    for(ll i=25;i>=0;i--){
        for(ll j=ch;j<x;j++){
            if((int)s[j]=='a'+i){
                l+=s[j];
                m1[s[j]]++;
                v.push_back(j);
                ch=j;
            }
        }
    }

    Sort(l);
    for(ll i=0;i<v.size();i++){
        s[v[i]]=l[i];
    }

    // finding the number of rotaions made.
    if(s==t){
        cout<<l.size()-1-(m1[l.back()]-1)<<endl;
    }
    else cout<<-1<<endl;
}
signed main()
{
    int t;cin>>t;
    while(t--){
        solve();        
    }

    return 0;
}