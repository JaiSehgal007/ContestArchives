/*
F. Shift and Reverse
time limit per test2.0 s
memory limit per test256 megabytes
inputstandard input
outputstandard output
Given an array of integers a1,a2,…,an
. You can make two types of operations with this array:

Shift: move the last element of array to the first place, and shift all other elements to the right, so you get the array an,a1,a2,…,an−1
.
Reverse: reverse the whole array, so you get the array an,an−1,…,a1
.
Your task is to sort the array in non-decreasing order using the minimal number of operations, or say that it is impossible.

Input
The first line of input contains a single integer t
 (1≤t≤104
) — the number of test cases. Descriptions of test cases follow.

The first line of each test case contains an integer n
 (1≤n≤105
) — size of the array.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109
) — elements of the array.

It is guaranteed that sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case output the number k
, the minimal number of operations you need to sort the array. If it is impossible to sort the array using these operations, output −1
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

signed main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi a(2*n);
        vi inc(2*n),dec(2*n+2);
        rep(i,0,n){cin>>a[i];a[i+n]=a[i];}
        rep(i,1,2*n){
            if(a[i]>=a[i-1])inc[i]=inc[i-1]+1;
            if(a[i]<=a[i-1])dec[i]=dec[i-1]+1;
        }

        int ans=INT_MAX;
        if(inc[n-1]==n-1)cout<<0<<endl;
        else if(dec[n-1]==n-1)cout<<1<<endl;
        else{
            rep(i,n,2*n){
                if(inc[i]==n-1)ans=min({ans,n-(i+1)%n,(i+1)%n+2});
                if(dec[i]==n-1)ans=min({ans,n-(i+1)%n+1,(i+1)%n+1});
            }
            if(ans==INT_MAX)cout<<-1<<endl;
            else cout<<ans<<endl;
        }


    }
    
    return 0;
}