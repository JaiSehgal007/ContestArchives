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
            string s;
        cin >> s;
        int n = s.size();
        long long mod = 1e9 + 7;
        long long ab_end_a=0;
        long long ab_end_b=0;
        long long a_end_a=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                ab_end_a=(ab_end_a + ab_end_b)%mod;
                a_end_a=(2*a_end_a+1)%mod;
            }else{
                ab_end_b=(ab_end_b + ab_end_a + a_end_a)%mod;
            }
        }
        cout<<(a_end_a+ ab_end_b)%mod<<endl;
    }

    return 0;
}