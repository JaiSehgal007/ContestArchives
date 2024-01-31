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

map<int,int> pf(int n) {
    map<int,int>mp;

    while (n % 2 == 0) {
        mp[2]++;
        n /= 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }

    if (n > 2) {
        mp[n]++;
    }

    return mp;
}

int find(int c,int p){
    set<int>mp;
    int pd=0;
    if(c%(p-1)==0)mp.insert(c/(p-1));
    mp.insert(c*(p-1));
    return max(1LL,(int)mp.size());
}

int mod=1e9+7;

signed main()
{
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        map<int,int>mp=pf(n);

        for(int i=0;i<q;i++){
            int p;cin>>p;
            int res=1;
            if(p==1){
                cout<<1<<endl;
            }else{
                for(auto m:mp){
                    if(m.second%p==0)res*=2;
                }
                cout<<res<<endl;
            }
        }

        
    }

    return 0;
}