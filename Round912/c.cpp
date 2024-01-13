/*
Theofanis easily gets obsessed with problems before going to sleep and often has 
nightmares about them. To deal with his obsession he visited his doctor, Dr. Emix.

In his latest nightmare, he has an array a
 of size n
 and wants to divide it into non-empty subarrays†
 such that every element is in exactly one of the subarrays.

For example, the array [1,−3,7,−6,2,5]
 can be divided to [1][−3,7][−6,2][5]
.

The Cypriot value of such division is equal to Σki=1i⋅sumi
 where k
 is the number of subarrays that we divided the array into and sumi
 is the sum of the i
-th subarray.

The Cypriot value of this division of the array 
[1][−3,7][−6,2][5]=1⋅1+2⋅(−3+7)+3⋅(−6+2)+4⋅5=17
.

Theofanis is wondering what is the maximum Cypriot value of any division of the array.

†
 An array b
 is a subarray of an array a
 if b
 can be obtained from a
 by deletion of several (possibly, zero or all) elements from the beginning and several 
 (possibly, zero or all) elements from the end. In particular, an array is a subarray of 
 itself.
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<long long>
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
        vi a(n);
        rep(i,0,a.size()){
            cin>>a[i];
        }
        
        vi suf(n+1,0);
        for(int i=n-1;i>=0;i--){
            suf[i]=suf[i+1]+a[i];
        }

        ll ans=suf[0];
        for(int i=1;i<n;i++){
            if(suf[i]>0){
                ans+=suf[i];
            }
        }
        cout<<ans<<endl;
        
    }

    return 0;
}