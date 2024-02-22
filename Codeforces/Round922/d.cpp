/*
You are given an array of numbers a1,a2,…,an
. Your task is to block some elements of the array in order to minimize its cost. Suppose you block the elements with indices 1≤b1<b2<…<bm≤n
. Then the cost of the array is calculated as the maximum of:

the sum of the blocked elements, i.e., ab1+ab2+…+abm
.
the maximum sum of the segments into which the array is divided when the blocked elements are removed. That is, the maximum sum of the following (m+1
) subarrays: [1,b1−1], [b1+1,b2−1], […], [bm−1+1,bm−1], [bm+1,n] (the sum of numbers in a subarray of the form [x,x−1] is considered to be 0).
For example, if n=6
, the original array is [1,4,5,3,3,2], and you block the elements at positions 2 and 5
, then the cost of the array will be the maximum of the sum of the blocked elements (4+3=7) 
and the sums of the subarrays (1, 5+3=8, 2), which is max(7,1,8,2)=8
.

You need to output the minimum cost of the array after blocking.

Input
The first line of the input contains a single integer t
 (1≤t≤30000
) — the number of queries.

Each test case consists of two lines. The first line contains an integer n
 (1≤n≤105
) — the length of the array a
. The second line contains n
 elements a1,a2,…,an
 (1≤ai≤109
) — the array a
.

It is guaranteed that the sum of n
 over all test cases does not exceed 105
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
        ll n;cin>>n;
        vector<ll>a(n+1),pre(n+2),dp(n+3);
        rep(i,0,n)cin>>a[i];

        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+a[i];
        }

        function<bool(int)> check=[&](int mid)->bool {
            dp[0]=0;
            deque<int>q;
            for(int i=0;i<=n;i++){
                while(q.size()>0 and dp[q.back()]>=dp[i]){
                    q.pop_back();
                }
                q.push_back(i);
                while(pre[i]-pre[q.front()]>mid){
                    q.pop_front();
                }
                dp[i+1]=dp[q.front()]+a[i];
            }
            return dp[n+1]<=mid;
        };

        int l=0,r=accumulate(begin(a),end(a),0LL);
        int ans=r;
        while(l<=r){
            long long mid=(l+r)/2;
            if(check(mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}