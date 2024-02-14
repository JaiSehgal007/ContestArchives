// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define ll long long
// #define pii pair<int,int>
// #define vii vector<pii>
// #define rep(i,a,b) for(int i=a;i<b;i++)
// #define ff first
// #define ss second
// #define setBits(x) __builtin_popcount(x)
// #define omp map<int,int>
// #define ump unordered_map<int,int>
// #define gri greater<int>
// #define pb push_back
// #define Sort(nums) sort(nums.begin(),nums.end())
// #define PQmin priority_queue<int,vi,gri>
// #define PQmax priority_queue<int,vi>
// int const Inf=1e9;
// int const N=1e5+3;

// void solve(){
//         int n,k;cin>>n>>k;
//         vvi ar(k);
//         rep(i,0,k){
//             for(int j=0;j<n;j++){
//                 int a;cin>>a;
//                 ar[i].push_back(a);
//             }
//         }

//         if(k<=1){
//             cout<<"YES"<<endl;
//             return;
//         }

//         int p1=-1,n1=-1,p2=-1,n2=-1;

//         for(int i=1;i<n;i++){
//             if(ar[0][i]==ar[1][0]){
//                 if(i!=1)p2=ar[0][i-1];
//                 if(i!=n-1)n2=ar[0][i+1];
//             }
//             if(ar[1][i]==ar[0][0]){
//                 if(i!=1)p1=ar[1][i-1];
//                 if(i!=n-1)n1=ar[1][i+1];
//             }
//         }

//         vi res;

//         if(p1==p2 and n1==n2){
//             if(p1==-1){
//                 res.push_back(ar[1][0]);
//             }
//             for(int i=1;i<n;i++){
//                 res.push_back(ar[1][i]);
//                 if(ar[1][i]==p1){
//                     res.push_back(ar[1][0]);
//                 }
//             }

            

//             if(k<=2){
//                 for(int i=0;i<k;i++){
//                     int miss=0;
//                     for(int j=1,k=0;j<n and k<n;j++){
//                         if(ar[i][j]!=res[k]){
//                             j--;
                            
//                             miss++;
//                         }
//                         k++;
//                     }
//                     if(miss>1){
//                         cout<<"NO"<<endl;
//                         return;
//                     }
//                 }

//                 cout<<"YES"<<endl;
//                 return;
//             }else{
//                 int ff=0;
//                 for(int i=1;i<n;i++){
//                     if(ar[2][i]==ar[1][0]){
//                         break;
//                     }
//                     if(ar[2][i]==ar[0][0]){
//                         ff=1;
//                         break;
//                     }
//                 }
//                 if(ff){
//                     for(int i=0;i<n;i++){
//                         if(res[i]==ar[1][0]){
//                             swap(res[i],res[i+1]);
//                             break;
//                         }
//                     }
//                 }

                

//                 for(int i=0;i<k;i++){
//                     int miss=0;
//                     for(int j=1,k=0;j<n and k<n;j++){
//                         if(ar[i][j]!=res[k]){
//                             j--;
                            
//                             miss++;
//                         }
//                         k++;
//                     }
//                     if(miss>1){
//                         cout<<"NO"<<endl;
//                         return;
//                     }
//                 }

//                 cout<<"YES"<<endl;
//                 return;
//             }
            
//         }else{
//             if(p2==-1){
//                 res.push_back(ar[1][0]);
//             }
//             for(int i=1;i<n;i++){
//                 res.push_back(ar[1][i]);
//                 if(ar[1][i]==p2){
//                     res.push_back(ar[1][0]);
//                 }
//             }

            

//             for(int i=0;i<k;i++){
//                 int miss=0;
//                 for(int j=1,k=0;j<n and k<n;j++){
//                     if(ar[i][j]!=res[k]){
//                         j--;
//                         miss++;
//                     }
//                     k++;
//                 }
//                 if(miss>1){
//                     cout<<"NO"<<endl;
//                     return;
//                 }
//             }
//             cout<<"YES"<<endl;
//             return;

            
//         }
        
// }

// signed main()
// {
//     int t;cin>>t;
//     while(t--){
//         solve();        
//     }

//     return 0;
// }


// above is a mathematical approach
// below is the data structure approach

#include <bits/stdc++.h>
using namespace std;
bool topological_sort(vector<vector<int>>& adj) {
  int n = adj.size();
  vector<int> indeg(n);
  for (int i = 0; i < n; i++) {
    for (int j : adj[i]) {
      indeg[j]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (indeg[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
      indeg[u]--;
      if (indeg[u] == 0) {
        q.push(u);
      }
    }
  }
  return (indeg == vector<int>(n, 0));
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(k, vector<int>(n));
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < k; i++) {
    for (int j = 1; j < n - 1; j++) {
      adj[a[i][j]].push_back(a[i][j + 1]);
    }
  }
  if (topological_sort(adj)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}