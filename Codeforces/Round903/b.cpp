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
        int a,b,c;cin>>a>>b>>c;
        vector<int>v={a,b,c};
        sort(begin(v),end(v));
        a=v[0];b=v[1];c=v[2];
        if(a%2!=0 || b%2!=0 || c%2!=0){
            if(a+b+c==6 || (a==b and b==c) || (a==b and (c==b*2 || c==b*3)) || (a!=b and b==a*2 and c==b) || (a*2==b and a*3==c)){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            if(a==b and b==c)cout<<"YES"<<endl;
            else if(a==b and b*2==c)cout<<"YES"<<endl;
            else if(a==b and (c==b*2 || c==b*3))cout<<"YES"<<endl;
            else if(a!=b and b==a*2 and c==b)cout<<"YES"<<endl;
            else if(a==b and b*4==c)cout<<"YES"<<endl;
            else if(a*2==b and a*3==c)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}