// https://www.youtube.com/watch?v=f99FEJV0Y8Q -> for explanation

/*
Some permutation of length n
 is guessed.

You are given the indices of its prefix maximums and suffix maximums.

Recall that a permutation of length k
 is an array of size k
 such that each integer from 1
 to k
 occurs exactly once.

Prefix maximums are the elements that are the maximum on the prefix ending at that element. More formally, the element ai
 is a prefix maximum if ai>aj
 for every j<i
.

Similarly, suffix maximums are defined, the element ai
 is a suffix maximum if ai>aj
 for every j>i
.

You need to output the number of different permutations that could have been guessed.

As this number can be very large, output the answer modulo 109+7
.
*/

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
const int MOD = 1e9 + 7;
const int N = 2e5 + 1;
 
int mod(int a, int m = MOD) {
    return a % m;
}
 
template <class T> class Math {
  public:
    vector<T> fact, invfact;
    Math() {}
    Math(int n) {
        fact.resize(n);
        invfact.resize(n);
        fact[0] = invfact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = mod(i * fact[i - 1]);
            invfact[i] = modinv(fact[i]);
        }
    }
    T modinv(T x, T m = MOD) { return expo(x, m - 2, m); }
    T expo(T base, T exp, T m = MOD) {
        T res = 1;
        while (exp) {
            if (exp & 1)
                res = mod(res * base, m);
            base = mod(base * base, m);
            exp >>= 1;
        }
        return res;
    }
    T choose(T n, T k) {
        if (k < 0 || k > n)
            return 0;
        T ans = fact[n];
        ans = mod(ans * invfact[n - k]);
        ans = mod(ans * invfact[k]);
        return ans;
    }
};

Math<int>math(N);

void solve(){
    int n,a,b;cin>>n>>a>>b;

    // form a tree like structure and then find permutations
    vector<int>arr1(a),arr2(b);
    for(auto &i:arr1)cin>>i;
    for(auto &i:arr2)cin>>i;

    if(arr1.front()!=1 || arr2.back()!=n || arr1.back() != arr2.front()){
        cout<<0<<endl;
    }else{
        vector<int>adj[n+1];

        for(int i=0;i+1<a;i++){
            adj[arr1[i+1]].push_back(arr1[i]);
            for(int j=arr1[i]+1;j<arr1[i+1];j++)adj[arr1[i]].push_back(j);
        }
        for(int i=0;i+1<b;i++){
            adj[arr2[i]].pb(arr2[i+1]);
            for(int j=arr2[i]+1;j<arr2[i+1];j++)adj[arr2[i+1]].pb(j);
        }

        // {size,answer of that branch}
        vii dp(n+1,{-1,-1});

        function<pair<int,int>(int)>dfs = [&](int node){
            if(dp[node].first!=-1)return dp[node];
            int sz=0,answer=1;
            
            for(auto &i:adj[node]){
                sz+=dfs(i).first;
            }

            int SZ=sz+1;

            for(auto &i:adj[node]){
                answer=(answer*(math.choose(sz,dfs(i).first)*dfs(i).second%MOD))%MOD;
                sz-=dfs(i).first;
            }

            return dp[node]={SZ,answer};
        };
        
        cout<<dfs(arr1.back()).second<<endl;
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