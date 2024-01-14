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
        string s;cin>>s;
        set<char>c={'b','c','d'};
        set<char>v={'a','e'};
        string res="";
        for(int i=0;i<n;i++){
            if(v.count(s[i+3])){
                res+=s[i];
                res+=s[i+1];
                res+='.';
                i=i+1;
            }else{
                res+=s[i];
                res+=s[i+1];
                res+=s[i+2];
                res+='.';
                i=i+2;
            }
        }
        res.pop_back();
        while(c.count(res.back())==0 and v.count(res.back())==0){
            res.pop_back();
        }
        cout<<res<<endl;
    }

    return 0;
}