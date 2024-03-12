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
        int l,r;cin>>l>>r;
        int n=r-l+1;

        vector<int>res(n);
        for(int i=l;i<=r;i++){
            res[i-l]=i;
        }

        if(n%2==0){
            for(int i=0;i<n;i+=2){
                swap(res[i],res[i+1]);
            }
            for(auto e:res)cout<<e<<" ";
            cout<<endl;
        }else{
            for(int i=0;i<n-1;i+=2){
                swap(res[i],res[i+1]);
            }
            int fl=0;
            for(int i=0;i<n-1;i+=2){
                if(__gcd(res[i],r)==1 and __gcd(res[i+1],r)==1){
                    swap(res[i],res.back());
                    fl=1;
                    break;
                }
            }
            if(fl){
                for(auto e:res)cout<<e<<" ";
                cout<<endl;
            }else{
                cout<<-1<<endl;
            }
        }




    }

    return 0;
}