/*
You are given two integers n
 and k
 along with a string s
.

Your task is to check whether all possible strings of length n
 that can be formed using the first k
 lowercase English alphabets occur as a subsequence of s
. If the answer is NO, you also need to print a string of length n
 that can be formed using the first k
 lowercase English alphabets which does not occur as a subsequence of s
.

If there are multiple answers, you may print any of them.

Note: A string a
 is called a subsequence of another string b
 if a
 can be obtained by deleting some (possibly zero) characters from b
 without changing the order of the remaining characters.
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

signed main()
{
    int t;cin>>t;
    while(t--){
        int n,k,m;cin>>n>>k>>m;
        string s;cin>>s;
        
        
        string res="";
        vector<bool>found(k,false);
        int count=0;

        for(char c:s){
            if(res.size()==n)break;
            count+=(!found[c-'a']);
            found[c-'a']=true;
            if(count==k){
                found=vector<bool>(k,false);
                count=0;
                res+=c;
            }
        }

        if(res.size()==n){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
            for(int i=0;i<k;i++){
                if(!found[i]){
                    while(res.size()<n){
                        res+=(char)('a'+i);
                    }
                }
            }
            cout<<res<<endl;
        }



    }

    return 0;
}