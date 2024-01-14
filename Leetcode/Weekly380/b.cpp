/*
You are given a 0-indexed string s, a string a, a string b, and an integer k.

An index i is beautiful if:

0 <= i <= s.length - a.length
s[i..(i + a.length - 1)] == a
There exists an index j such that:
0 <= j <= s.length - b.length
s[j..(j + b.length - 1)] == b
|j - i| <= k
Return the array that contains beautiful indices in sorted order from smallest to largest.
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

class Solution {
public:
    vector<int> buildLPS(const std::string& pattern) {
        int m = pattern.length();
        std::vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
    
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    
        return lps;
    }
    
    vector<int> kmp(const std::string& text, const std::string& pattern) {
        std::vector<int> result;
        int n = text.length();
        int m = pattern.length();
        vector<int> lps = buildLPS(pattern);
    
        int i = 0; 
        int j = 0;  
    
        while (i < n) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }
    
            if (j == m) {
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
    
        return result;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        map<int,int>ma,mb;
        vector<int>mav=kmp(s,a),mab=kmp(s,b);
        for(auto e:mav)ma[e]++;
        for(auto e:mab)mb[e]++;
        vector<int>res;
        for(auto m:ma){
            auto it=mb.upper_bound(m.first);
            int fl=0;
            if(it!=mb.end() and abs(m.first-(*it).first)<=k)res.push_back(m.first);
            else if(it!=mb.begin()){
                it--;
                if(abs(m.first-(*it).first)<=k)res.push_back(m.first);
            }
        }
        return res;
    }
};

signed main()
{
    int t;cin>>t;
    while(t--){
    }

    return 0;
}