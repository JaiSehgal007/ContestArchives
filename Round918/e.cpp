#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define forn(i,n)       for(int i=0 ; i<n ; i++)           
 
void c_p_c()
{
    w(t)
    {
        int n;
        cin>>n;
        vi v(n);
        forn(i,n)
        {
            cin>>v[i];
            if(i%2 == 1)
            {
                v[i] = -v[i];
            }
        }

        vi pref(n+1);
        pref[0] = 0;
        for(int i=1 ; i<=n ; i++)
        {
            pref[i] = pref[i-1] + v[i-1];
        }
        sort(pref.begin() , pref.end());
        int flag = -1;
        forn(i,n)
        {
            if(pref[i] == pref[i+1])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
 
int32_t main()
{
    c_p_c();
    return 0;
}