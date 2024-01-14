/*
G. Lights
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
In the end of the day, Anna needs to turn off the lights in the office. There are n
 lights and n
 light switches, but their operation scheme is really strange. The switch i
 changes the state of light i
, but it also changes the state of some other light ai
 (change the state means that if the light was on, it goes off and vice versa).

Help Anna to turn all the lights off using minimal number of switches, or say it is impossible.

Input
The first line of input contains a single integer t
 (1≤t≤104
) — the number of test cases. Descriptions of test cases follow.

The first line of each test case contains the integer n
 (2≤n≤105
) — the number of lights.

The second line of each test case contains the string of n
 characters, the initial state of the lights. Character "0" means that the corresponding light is off, and "1" means that it is on.

The third line of each test case contains n
 integers ai
 (1≤ai≤n
, ai≠i
) — the switch i
 changes the states of light i
 and light ai
.

It is guaranteed that sum of n
 over all test cases does not exceed 2⋅105
Output
For each test case output the integer k
, the minimal number of switches to use, then in the separate line output the list of k
 switches.

If it is impossible to turn off all the lights, output single integer −1
.
*/

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

void solve(){
        int n;cin>>n;
        string ss;cin>>ss;

        vector<bool>s(n);
        rep(i,0,n)s[i]=(ss[i]=='1');

        vi a(n);
        rep(i,0,a.size()){
            cin>>a[i];
            a[i]--;
        }

        vi res,d(n);

        rep(i,0,n)d[a[i]]++;

        vi z;
        for(int i=0;i<n;i++){
            if(d[i]==0)z.pb(i);
        }

        for(int i=0;i<z.size();i++){
            int x=z[i];
            int y=a[x];

            if(s[x]){
                res.push_back(x);
                s[x]=!s[x];
                s[y]=!s[y];
            }
            d[y]--;
            if(d[y]==0){
                z.push_back(y);
            }
        }

        vector<bool>u(n);
        for(int i=0;i<n;i++){
            if(s[i] and !u[i]){
                int x=i;
                vector<int>p;
                vector<bool>ps;
                int c=0;
                while(!u[x]){
                    p.push_back(x);
                    ps.push_back(s[x]);
                    c+=s[x];
                    u[x]=true;
                    x=a[x];
                }
                int k=p.size();
                p.push_back(x);
                ps.push_back(s[x]);
                if(c%2==1){
                    cout<<-1<<endl;
                    return;
                }
                vector<int>v1;
                vector<bool>ps1=ps;
                for(int j=0;j<k;j++){
                    if(j==0 || ps1[j]){
                        v1.push_back(p[j]);
                        ps1[j]=!ps1[j];
                        ps1[j+1]=!ps1[j+1];
                    }
                }
                vector<int>v2;
                vector<bool>ps2=ps;
                for (int j = 0; j < k; j++) {
                    if (j != 0 && ps2[j]) {
                        v2.push_back(p[j]);
                        ps2[j] = !ps2[j];
                        ps2[j + 1] = !ps2[j + 1];
                    }
                }

                if(v1.size()<v2.size()){
                    for(auto x:v1){
                        res.push_back(x);
                    }
                }else{
                    for(auto x:v2){
                        res.push_back(x);
                    }
                }
            }
        }

        cout<<res.size()<<endl;
        for(auto x:res)cout<<x+1<<" ";
        cout<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        solve();        
    }

    return 0;
}