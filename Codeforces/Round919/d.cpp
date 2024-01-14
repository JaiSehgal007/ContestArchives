#include<bits/stdc++.h>
using namespace std;

#define int int64_t
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

int safeMultiply(int a, int b) {
    if (a > LLONG_MAX / b) return LLONG_MAX;  
    return a * b;
}


int finde(int i,map<int,int>&mp){
    if(mp.find(i)!=mp.end())return mp[i];
    auto it=mp.lower_bound(i);
    if(it==mp.begin())return (*it).second;
    it--;
    int sz=(*it).first;
    if(i%sz==0)return (*it).second;
    int apos=i%sz;
    return finde(apos,mp);
}

signed main()
{
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        map<int,int>pos;
        int sz=0,fl=1;
        for(int i=0;i<n;i++){
            int a,b;cin>>a>>b;
            if(sz==LLONG_MAX)continue;
            if(a==1){
                pos[sz+1]=b;
                sz++;
            }
            else{
                sz=safeMultiply(sz, b + 1);  // Use a function to handle overflow
            }
        }
        while(q--){
            int f;cin>>f;
            cout<<finde(f,pos)<<" ";
        }
        cout<<endl;
    }

    return 0;
}