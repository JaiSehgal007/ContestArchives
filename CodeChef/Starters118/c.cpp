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
        int x;cin>>x;
        
        vector<int>ans;
        for(int i=0;i<32;i++){
            if(x&(1<<i)){
                ans.pb((1<<i));
            }
        }
        
        for(int i=1;i<ans.size();i++){
            ans[i]+=ans[i-1];
        }
        
        int res=ans.back()-2*ans[0];
        
        for(int i=1;i<ans.size();i++){
            if(ans.back()-2*ans[i] > 0)res=min(res,ans.back()-2*ans[i]);
        }
        
        int diff=res;
        int sum=ans.back();

        int a=(sum+diff)/2LL;
        int b=(sum-diff)/2LL;

        cout<<min(a,b)<<" "<<max(a,b)<<endl;
    }

    return 0;
}