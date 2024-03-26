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

int findRot(vector<string> &a, int N)
{
    int res=0;
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            vector<char>tmp;
            tmp.pb(a[i][j]);
            tmp.pb(a[N - 1 - j][i]);
            tmp.pb(a[N - 1 - i][N - 1 - j]);
            tmp.pb(a[j][N - 1 - i]);
            sort(begin(tmp),end(tmp));
            for(int i=0;i<3;i++){
                res+=(tmp.back()-tmp[i]);
            }
        }
    }
    return res;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<string>mat;
        for(int i=0;i<n;i++){
            string tmp;cin>>tmp;
            mat.pb(tmp);
        }
        cout<<findRot(mat,n)<<endl;
    }

    return 0;
}