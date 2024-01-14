/*
Maximum Number That Sum of the Prices Is Less Than or Equal to K

You are given an integer k and an integer x.

Consider s is the 1-indexed binary representation of an integer num. The price of a number num is the number of i's such that i % x == 0 and s[i] is a set bit.

Return the greatest integer num such that the sum of prices of all numbers from 1 to num is less than or equal to k.

Note:

In the binary representation of a number set bit is a bit of value 1.
The binary representation of a number will be indexed from right to left. For example, if s == 11100, s[4] == 1 and s[2] == 0.
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

class Solution {
public:
    long long k,x;
    long long getcount(long long n, long long i)
    {
        n++;
        long long res = (n >> min(i + 1, 63LL)) << i;
        if ((n >> i) & 1)res += n & ((1ll << i) - 1);
        return res;
    }
    bool poss(long long &num){
        long long sum=0;
        
        for(long long i=0;i<64;i++){
            
            if((i+1)%x==0){
                sum+=getcount(num,i);
                if(sum>k)return false;
            }
        }
        
        
        if(sum<=k)return true;
        return false;
    }
    long long findMaximumNumber(long long k, int x) {
        this->k=k;
        this->x=x;
        long long res=0,lo=0,hi=1e15+1;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if(poss(mid)){
                res=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return res;        
    }
};

signed main()
{
    int t;cin>>t;
    while(t--){
    }

    return 0;
}