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
        string s;cin>>s;
        int n=s.size();
        vi ls,lb;
        set<int>rem;
        for(int i=0;i<n;i++){
            if(s[i]>='a' and s[i]<='z'){
                if(s[i]!='b')ls.pb(i);
                else{
                    if(ls.size()){
                        rem.insert(ls.back());
                        ls.pop_back();
                    }
                    rem.insert(i);
                }
            }else{
                if(s[i]!='B')lb.pb(i);
                else{
                    if(lb.size()){
                        rem.insert(lb.back());
                        lb.pop_back();
                    }
                    rem.insert(i);
                }
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(rem.count(i)==0)ans+=s[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}