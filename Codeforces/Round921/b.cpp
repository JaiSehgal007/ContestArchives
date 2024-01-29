/*
Jay managed to create a problem of difficulty x
and decided to make it the second problem for Codeforces Round #921.

But Yash fears that this problem will make the contest highly unbalanced, and 
the coordinator will reject it. So, he decided to break it up into a problemset of n
sub-problems such that the difficulties of all the sub-problems are a positive 
integer and their sum is equal to x

The coordinator, Aleksey, defines the balance of a problemset as the GCD of the 
difficulties of all sub-problems in the problemset.

Find the maximum balance that Yash can achieve if he chooses the difficulties of the 
sub-problems optimally.
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
int const Inf=1e9;
int const N=1e5+3;

signed main()
{
    int t;cin>>t;
    while(t--){
        int x,n;cin>>x>>n;
        // GCD(a1,a2,a3,…,an)=GCD(a1,a1+a2,a1+a2+a3,…,a1+a2+a3+…+an)
        // GCD(a1,a2,a3,…,an)=GCD(a1,a1+a2,a1+a2+a3,…,x)
        // this means it is a divisor of x
        int ans=1;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                if(n<=x/i){
                    ans=max(ans,i);
                }
                if(n<=i){
                    ans=max(ans,x/i);
                }
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}