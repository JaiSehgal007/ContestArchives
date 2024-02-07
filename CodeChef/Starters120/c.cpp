#include <bits/stdc++.h>
using namespace std;

int mod=998244353;


long long find(long long A, long long B)
{
    if (B == 0)return 1;
    long long res = (find(A, B / 2)%mod);
 
    if (B % 2)return ((res * res * A)%mod);
    else return ((res * res)%mod);
}
int main() {
	int t;cin>>t;
	while(t--){
	    int n,k;cin>>n>>k;
	    long long p=(long long)((long long)(k)*(long long)(n-1));
        cout<<(find(2,p)%mod)<<endl;
	}
}
