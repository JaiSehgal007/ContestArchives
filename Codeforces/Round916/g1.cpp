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
int mod=998244353;

signed main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi c(2*n);
        for(auto &e: c)     cin>>e;
        vi a(n+1,-1),b(n+1); // a-> first pos og the bulb and b->second pos

        for(int i=0;i<2*n;i++){
            if(a[c[i]]==-1)a[c[i]]=i;
            else b[c[i]]=i;
        }

        ll x=0,y=1;

        // x -> min set size, y->number of ways\

        vi cnt(2*n+1);
        set<int>st,st2;
        vi rem;

        //  to find the number of elements in my set
        for(int i=0;i<2*n;){

            // computing one partisian size from j->new i
            st2.insert(c[i]);
            cnt[c[i]]=1;

            int j=i;

            i++;
            while(i<2*n and st2.size()){
                if(!cnt[c[i]]){
                    st2.insert(c[i]);
                    cnt[c[i]]=1;
                }else{
                    st2.erase(c[i]);
                }
                i++;
            }

            x++;


            // what all position in this are valid

            int val=0;

            for(int l=j,k,mmin,mmax;l<i;l++){
                st.clear();
                for(int _=j;_<i;_++)st.insert(_);

                rem.clear();
                rem.pb(l);

                while(rem.size()){
                    mmin=a[c[rem.back()]];
                    mmax=b[c[rem.back()]];

                    rem.pop_back();

                    while(st.lower_bound(mmin)!=st.end() and *st.lower_bound(mmin)<=mmax){
                        k=*st.lower_bound(mmin);
                        st.erase(k);
                        rem.push_back(k);
                    }
                }
                val+=(st.size()==0);
            }
            (y*=val)%=mod;
        }

        cout<<x<<" "<<y<<endl;


    }

    return 0;
}