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
    int t;
	cin>>t;
	while(t--){
	    int n, i;
	    cin>>n;
	    
	    int arr[2*n];
	    unordered_map<int, int>mp;
	    vector<pair<int, int>>v;
	    
	    for(i=0;i<2*n;i++){
	        cin>>arr[i];
	        if(mp.find(arr[i])!=mp.end())
	            mp[arr[i]]=i-mp[arr[i]];
	        else 
	            mp[arr[i]]=i;
	    }
	    
	    
	    for(auto x: mp){
	        v.push_back({x.second, x.first});
	    }
	    
	    sort(v.begin(), v.end());
	    
	    for(i=v.size()-1;i>=0;i--){
	        cout<<v[i].second<<" ";
	    }
	    cout<<endl;
	}

    return 0;
}