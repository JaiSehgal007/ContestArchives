/*
There are n
 children in a class, m
 pairs among them are friends. The i
-th pair who are friends have a friendship value of fi
.

The teacher has to go for k
 excursions, and for each of the excursions she chooses a pair of children randomly, equiprobably and independently. If a pair of children who are friends is chosen, their friendship value increases by 1
 for all subsequent excursions (the teacher can choose a pair of children more than once). The friendship value of a pair who are not friends is considered 0
, and it does not change for subsequent excursions.

Find the expected value of the sum of friendship values of all k
 pairs chosen for the excursions (at the time of being chosen). It can be shown that this answer can always be expressed as a fraction pq
 where p
 and q
 are coprime integers. Calculate p⋅q−1mod(109+7)
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤5⋅104
). Description of the test cases follows.

The first line of each test case contains 3
 integers n
, m
 and k
 (2≤n≤105
, 0≤m≤min(105
, n(n−1)2)
, 1≤k≤2⋅105
) — the number of children, pairs of friends and excursions respectively.

The next m
 lines contain three integers each — ai
, bi
, fi
 — the indices of the pair of children who are friends and their friendship value. (ai≠bi
, 1≤ai,bi≤n
, 1≤fi≤109
). It is guaranteed that all pairs of friends are distinct.

It is guaranteed that the sum of n
 and sum m
 over all test cases does not exceed 105
 and the sum of k
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print one integer — the answer to the problem.
*/

// https://www.youtube.com/watch?v=P0DPguMxcxg

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
struct Mint {
    int val;
 
    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        } 
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    // friend Mint operator<=(const Mint &a, const Mint &b) { return (int)a <= (int)b; }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;   
    }
};

signed main()
{
    int t;cin>>t;
    while(t--){
        int n,m,k;cin>>n>>m>>k;

        Mint sumF=0;
        for(int i=0;i<m;i++){
            int a,b,f;cin>>a>>b>>f;
            sumF+=f;
        }

        Mint mx=(Mint) n*(n-1)/2;
        Mint ans=0;

        for(int i=0;i<k;i++){
            ans+=sumF/mx;
            sumF+=m/mx;
        }
        cout<<ans<<endl;
    }

    return 0;
}