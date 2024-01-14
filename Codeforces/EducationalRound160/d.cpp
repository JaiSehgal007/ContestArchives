/*
D. Array Collapse
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array [p1,p2,…,pn]
, where all elements are distinct.

You can perform several (possibly zero) operations with it. In one operation, you can choose a contiguous subsegment of p
 and remove all elements from that subsegment, except for the minimum element on that subsegment. For example, if p=[3,1,4,7,5,2,6]
 and you choose the subsegment from the 3
-rd element to the 6
-th element, the resulting array is [3,1,2,6]
.

An array a
 is called reachable if it can be obtained from p
 using several (maybe zero) aforementioned operations. Calculate the number of reachable arrays, and print it modulo 998244353
.

Input
The first line of the input contains one integer t
 (1≤t≤104
) — the number of test cases.

Each test case consists of two lines. The first line contains one integer n
 (1≤n≤3⋅105
). The second line contains n
 distinct integers p1,p2,…,pn
 (1≤pi≤109
).

Additional constraint on the input: the sum of n
 over all test cases does not exceed 3⋅105
.

Output
For each test case, print one integer — the number of reachable arrays, taken modulo 998244353
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
int const N=300010;
int mod=998244353;


// DISTANCE FUNTION GIVES TLE IN THIS CASE..TO AVOID YOU MAY USE SEGMENT TREES OR SPARSE TABLE

int a[N],n,lg[N];
pair<int,int> st[20][N];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<20;j++){
			st[j][i]={2e9,i};
		}
	}
	for(int i=1;i<=n;i++){
		st[0][i]={a[i],i};
	}
	for(int j=1;j<20;j++){
		for(int i=1;i+(j<<1)-1<=n;i++){
			st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
		}
	}
}
int query(int l,int r){
	int len=lg[r-l+1];
	return min(st[len][l],st[len][r-(1<<len)+1]).ss;
}

int ans(int l,int r,bool ld,bool rd){
    if(l>r)return 1;
    if(l==r)return ((ld||rd)?2:1);
    else{
        int mid=query(l,r);
        int ansl=ans(l,mid-1,ld,true),ansr=ans(mid+1,r,true,rd);
        int ans=0;
        ans+=(ansl*ansr)%mod;
        if(ld)ans+=ansr-1;
        if(rd)ans+=ansl-1;
        if(ld||rd)ans++;
        return ans%mod;
    }
}

void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
    }
    init();
    cout<<ans(1,n,false,false)<<endl;
    
}



signed main() 
{
	std::ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
	int _=1;
	cin>>_;
	for(int i=2;i<N;i++){
		lg[i]=lg[i/2]+1;
	}
	while(_--){
		solve();
	}
    return 0;
}