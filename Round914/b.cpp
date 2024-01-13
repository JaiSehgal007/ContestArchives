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
        int n,tmp=0;cin>>n;
        vvi a,st;
        for(int i=0;i<n;i++){
            int s;cin>>s;
            a.pb({s,i});
        }
        sort(begin(a),end(a));
        vi res(n,0);
        rep(i,0,n){
            if(a[i][0]>tmp){
                while(st.size()){
                    res[st.back()[1]]=i-1;
                    st.pop_back();
                }
            }
            tmp+=a[i][0];
            st.pb(a[i]);
        }
        while(st.size()){
            res[st.back()[1]]=n-1;
            st.pop_back();
        }
        rep(i,0,n){
            cout<<res[i]<<" ";
        }cout<<endl;
        
    }

    return 0;
}