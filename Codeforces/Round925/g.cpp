// use of stars and bars theoram
// if we have to put n identical objects into k unique groups
// then there are two formulas
// 1. if the groups can be empty : (n-1)C(k-1)
// 2. if the groups cannot be empty : (n+k-1)C(k-1)


/*
You have a one-dimensional puzzle, all the elements of which need to be put in one row, connecting with each other. All the puzzle elements are completely white and distinguishable from each other only if they have different shapes.

Each element has straight borders at the top and bottom, and on the left and right it has connections, each of which can be a protrusion or a recess. You cannot rotate the elements.

You can see that there are exactly 4
 types of elements. Two elements can be connected if the right connection of the left element is opposite to the left connection of the right element.

All possible types of elements.
The puzzle contains c1,c2,c3,c4
 elements of each type. The puzzle is considered complete if you have managed to combine all elements into one long chain. You want to know how many ways this can be done.

Input
The first line contains a single integer t
 (1≤t≤2⋅105
) — the number of input test cases. The descriptions of the test cases follow.

The description of each test case contains 4
 integers ci
 (0≤ci≤106
) — the number of elements of each type, respectively.

It is guaranteed that the sum of ci
 for all test cases does not exceed 4⋅106
.

Output
For each test case, print one integer — the number of possible ways to solve the puzzle.

Two methods are considered different if there is i
, such that the types of elements at the i
 position in these methods differ.

Since the answer can be very large, output it modulo 998244353
.

If it is impossible to solve the puzzle, print 0
.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;
#define YES cout << "YES\n"
#define NO cout << "NO\n"

template <int P = 998244353> class Mint {
    using i64 = long long;
    using i128 = __uint128_t;
    using ValueType = int;
 
  private:
    ValueType x;
    template <typename T> constexpr T fast_pow(T base, ValueType power) const {
        T res = 1;
        while (power > 0) {
            if (power & 1)
                res = res * base;
            base = base * base;
            power >>= 1;
        }
        return res;
    }
 
  public:
    // Constructor
    constexpr Mint() : x{0} {}
    constexpr Mint(int v) : x{norm(v % getMod())} {}
    constexpr Mint(long long v) : x{norm(v % getMod())} {}
    constexpr Mint(__int128_t v) : x{norm(v % getMod())} {}
    constexpr Mint(const Mint &i) { this->x = i.val(); }
    constexpr Mint(Mint &i) { this->x = i.val(); }
    constexpr Mint(Mint &&i) { this->x = i.val(); }
    // Modulo related
    static ValueType getMod() {
        if (P > 0)
            return P;
    }
    // Normalize
    constexpr ValueType norm(ValueType x) const {
        if (x < 0)
            x += getMod();
        else if (x >= getMod())
            x -= getMod();
        return x;
    }
    constexpr ValueType val() const { return x; }
    // Type Convertor
    explicit constexpr operator int() const { return int(x); }
    explicit constexpr operator long long() const { return (long long)(x); }
    /* Arithmetic */
    // Negative sign
    constexpr Mint operator-() const {
        Mint res;
        res.x = norm(getMod() - x);
        return res;
    }
    // Inverse
    constexpr Mint inv() const { return fast_pow(*this, getMod() - 2); }
    constexpr Mint &operator*=(Mint rhs) & {
        x = 1LL * x * rhs.val() % getMod();
        return *this;
    }
    constexpr Mint &operator+=(Mint rhs) & {
        x = norm(x + rhs.val());
        return *this;
    }
    constexpr Mint &operator-=(Mint rhs) & {
        x = norm(x - rhs.val());
        return *this;
    }
    constexpr Mint &operator/=(Mint rhs) & { return *this *= rhs.inv(); }
    constexpr Mint &operator=(Mint rhs) & {
        this->x = rhs.val();
        return *this;
    }
    friend constexpr Mint operator*(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr Mint operator+(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr Mint operator-(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr Mint operator/(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
    /* Input Output */
    friend constexpr std::istream &operator>>(std::istream &is, Mint &a) {
        ValueType v;
        is >> v;
        a = Mint(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const Mint &a) {
        return os << a.val();
    }
    /* Bool Judges */
    friend constexpr bool operator==(Mint lhs, Mint rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(Mint lhs, Mint rhs) {
        return lhs.val() != rhs.val();
    }
    friend constexpr bool operator<(Mint lhs, Mint rhs) {
        return lhs.val() < rhs.val();
    }
    friend constexpr bool operator>(Mint lhs, Mint rhs) {
        return lhs.val() > rhs.val();
    }
    friend constexpr bool operator<=(Mint lhs, Mint rhs) {
        return lhs.val() <= rhs.val();
    }
    friend constexpr bool operator>=(Mint lhs, Mint rhs) {
        return lhs.val() >= rhs.val();
    }
    /* Advanced Arithmetic */
    constexpr Mint &operator++() & {
        this->x = this->norm(this->x + 1);
        return *this;
    }
    constexpr Mint &operator--() & {
        this->x = this->norm(this->x - 1);
        return *this;
    }
    constexpr Mint operator++(int) {
        auto f = Mint(x);
        this->x = this->norm(this->x + 1);
        return f;
    }
    constexpr Mint operator--(int) {
        auto f = Mint(x);
        this->x = this->norm(this->x - 1);
        return f;
    }
    constexpr Mint &operator^=(const Mint &a) & {
        *this = fast_pow(*this, a.val());
        return *this;
    }
    constexpr Mint operator^(const Mint &a) const {
        auto f = Mint(this->x);
        f ^= a;
        return f;
    }
};
 
class Combination {
  private:
    int n;
    vector<Mint<>> _fac, _invfac, _inv;
 
  public:
    Combination() : n{0}, _fac{1}, _inv{1}, _invfac{1} {}
    Combination(int N) : Combination() { init(N); }
    void init(int m) {
        if (m <= n)
            return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }
    Mint<> fac(int m) {
        if (m > n)
            init(2 * m);
        return _fac[m];
    }
    Mint<> invfac(int m) {
        if (m > n)
            init(2 * m);
        return _invfac[m];
    }
    Mint<> inv(int m) {
        if (m > n)
            init(2 * m);
        return _inv[m];
    }
    Mint<> binom(int n, int m) {
        if (n < m || m < 0)
            return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

void solve(){
    int a,b,c,d;cin>>a>>b>>c>>d;
    if(abs(a-b)>=2)
        return cout<<"0\n",void();

    Mint ans;
    if(a==0 and b==0){
        ans= (c==0) || (d==0);
    }else if(a+1==b){
        ans=comb.binom(d+b-1,b-1)*comb.binom(c+b-1,b-1);
    }else if(a-1==b){
        ans=comb.binom(d+a-1,a-1)*comb.binom(c+a-1,a-1);
    }else{
        ans = comb.binom(c+a-1,a-1)*comb.binom(d+a,a) +
              comb.binom(d+a-1,a-1)*comb.binom(c+a,a);
    }
    cout<<ans<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}