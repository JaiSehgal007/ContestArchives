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
    string s;cin>>s;
    for(int i=1;i<s.size();i++){
        int n1=stoi(s.substr(0,i));
        int n2=stoi(s.substr(i));
        if(n2>n1 and (to_string(n1)+to_string(n2)==s)){
            cout<<n1<<" "<<n2<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}