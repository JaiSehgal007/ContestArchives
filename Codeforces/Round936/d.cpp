/*
Yarik's birthday is coming soon, and Mark decided to give him an array a
 of length n
.

Mark knows that Yarik loves bitwise operations very much, and he also has a favorite number x
, so Mark wants to find the maximum number k
 such that it is possible to select pairs of numbers [l1,r1
], [l2,r2
], …
 [lk,rk
], such that:

l1=1
.
rk=n
.
li≤ri
 for all i
 from 1
 to k
.
ri+1=li+1
 for all i
 from 1
 to k−1
.
(al1⊕al1+1⊕…⊕ar1)|(al2⊕al2+1⊕…⊕ar2)|…|(alk⊕alk+1⊕…⊕ark)≤x
, where ⊕
 denotes the operation of bitwise XOR, and |
 denotes the operation of bitwise OR.

 If such k
 does not exist, then output −1
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
int const Inf=1e9;
int const N=1e5+3;

void solve(){
    int n,x,answer=0;cin>>n>>x;
    vi a(n);
    rep(i,0,a.size()){
        cin>>a[i];
    }

    auto calc=[&](int MSB){
        int sz=0,lastIdx=-1,Xor=0,Or=0;
        for(int i=0;i<n;i++){
            Xor^=a[i];
            int mask=INT_MAX-((1<<(MSB+1))-1);
            if((mask & Xor)==(mask&Xor&x) and (Xor&(1ll<<MSB))==0 and Xor<=x){
                Or|=Xor;
                Xor=0;
                sz++;
                lastIdx=i;
            }
        }

        if(lastIdx!=(n-1) || Or>x)return 0LL;

        return sz;
    };

    
    for(int i=0;i<=30;i++){
        answer=max(answer,calc(i));
    }
    cout<<(answer==0?-1:answer)<<endl;

}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}