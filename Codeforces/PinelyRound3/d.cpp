
// There are n
//  positive integers a1,a2,…,an
//  on a blackboard. You are also given a positive integer k
// . You can perform the following operation some (possibly 0
// ) times:

// choose a number x
//  on the blackboard;
// erase one occurrence of x
// ;
// write two positive integers y
// , z
//  such that y+z=x+k
//  on the blackboard.
// Is it possible to make all the numbers on the blackboard equal? If yes, what is the minimum number of operations you need?

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤104
// ). The description of the test cases follows.

// The first line of each test case contains two integers n
// , k
//  (1≤n≤2⋅105
// , 1≤k≤1012
// ) — the number of integers initially on the blackboard and the constant k
// .

// The second line of each test case contains n
//  integers a1,a2,…,an
//  (1≤ai≤1012
// ) — the initial state of the blackboard.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, output a single line containing an integer: the minimum number of operations you need to make all the numbers on the blackboard equal, or −1
//  if it is impossible.


// SOLUTION

// Consider the "shifted" problem, where each x
//  on the blackboard (at any moment) is replaced with x′=x−k
// .


// Now, the operation becomes "replace x
//  with y+z
//  such that y+z=x+k⟹(y′+k)+(z′+k)=(x′+k)+k⟹y′+z′=x′
// ". Therefore, in the shifted problem, k′=0
// .

// Now you can replace every a′i:=ai−k
//  with any number of values with sum a′i
// , and the answer is the amount of numbers on the blackboard at the end, minus n


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

void solve(){
    ll n,k;cin>>n>>k;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
        a[i]-=k;
    }
    Sort(a);

    if(a[0]==0 and a.back()==0){
        cout<<0<<endl;
        return;
    }

    // this runs only on cpp 20 version😁
    // normal method do not work as the range is going even out of long long
    if((__int128)a[0] * a[n - 1] <= 0LL){
		cout << "-1\n"; 
        return;
	}

    rep(i,0,n)a[i]=abs(a[i]);

    ll g=a[0],ans=0;

    rep(i,1,n)g=__gcd(g,a[i]);

    rep(i,0,n)ans+=((a[i]/g)- 1);

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


/*
For Older version of cpp

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main () {


	int t; cin >> t;
	while (t --) {
		ll n, k; cin >> n >> k;
		ll g = 0;
		ll arr[n + 1]; for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			arr[i] -= k;
			g = __gcd(g, arr[i]);
		}

		if (!g) {
			cout << 0 << '\n';
			continue;
		}
		if (g + k < 1){
			cout << -1 << '\n';
			continue;
		}
		ll ans = 0;
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			ok &= ((arr[i] % g == 0) and ((arr[i] / g) > 0));
			ans += arr[i] / g;
		}
		if (!ok)ans = -1 + n;
		cout << ans - n << '\n';
	
	}

	return 0;
}
*/