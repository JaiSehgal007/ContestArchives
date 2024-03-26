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

void findFactors(int n,ump &mp) 
{  
    if(n<=1)return;
    while (n % 2 == 0) 
    { 
        mp[2]++;
        n = n/2; 
    } 
 
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        while (n % i == 0) 
        { 
            mp[i]++; 
            n = n/i; 
        } 
    } 
 
    if (n > 2) 
        mp[n]++;
} 

signed main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi a(n);
        rep(i,0,a.size()){
            cin>>a[i];
        }
        ump multiples;
        rep(i,0,n){
            findFactors(a[i],multiples);
        }
        bool fl=0;
        for(auto m:multiples){
            if(m.second%n!=0){
                cout<<"NO"<<endl;
                fl=1;
                break;
            }
        }
        if(fl)continue;
        cout<<"YES"<<endl;
    }

    return 0;
}