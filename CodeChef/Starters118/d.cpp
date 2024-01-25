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
		ll x;
		cin>>x;
		ll count = 0;
		while((x&(x-1)) != 0)
		{
		    if((x%2) == 0)
		    {
		        count++;
		    }
		    x = x>>1;
		}
		ll ans=(pow(2,count));
		cout<<ans<<endl;
    }

    return 0;
}


/*
more intutive

    int n;
    cin>>n;
    int a = 1;
    int b = 0;
    int count = 0;
    while (a*2<=n){
        a = a*2;
        count++;
    }
    int ans = 1;
    bool check = false;
    for (int i = count - 1; i >= 0; i--) {
        if ((n&1<<i)){
            b = b | (1<<i);
            check = true;
        } else {
            if (check) ans = ans * 2;
        }
    }
    cout<<ans<<endl;
*/