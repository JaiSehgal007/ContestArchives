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


int minSwaps(char ch,string s) {
    int total_ch = 0;
    for (char c : s) {
        if (c == ch) {
            total_ch++;
        }
    }

    if(total_ch==0)return INT_MAX;

    int current_ch = 0;
    for (int i = 0; i < total_ch; i++) {
        if (s[i] == ch) {
            current_ch++;
        }
    }

    int min_swaps = total_ch - current_ch;

    for (int i = total_ch; i < s.length(); i++) {
        current_ch += (s[i] == ch);
        current_ch -= (s[i - total_ch] == ch);
        min_swaps = min(min_swaps, total_ch - current_ch);
    }

    return min_swaps;
}

signed main()
{
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;

        int ans=INT_MAX;
        for(int i=0;i<26;i++){
            ans=min(ans,minSwaps((char)(i+'a'),s));
        }

        cout<<ans<<endl;

    }

    return 0;
}