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

int mod=1e9+7;

int msa(vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum%mod;
}


void solve(){
    int n,k;cin>>n>>k;
    vi a(n);
    rep(i,0,a.size()){
        cin>>a[i];
    }
    
    int sum=msa(a);
    int asum=accumulate(begin(a),end(a),0LL)-sum;

    if(sum<=0){
        cout<<(((asum+sum)%mod)+mod)%mod<<endl;
        return;
    }

    for(int i=0;i<k;i++){
        sum*=2;
        sum%=mod;
    }

    cout<<(((asum+sum)%mod)+mod)%mod<<endl;

}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}