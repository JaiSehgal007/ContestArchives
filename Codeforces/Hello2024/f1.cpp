#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)


const int LINF = 1000000000000000005;
const int MAXN = 500005;

int n, q;
int a[MAXN], b[MAXN];
int c[MAXN];
int v[MAXN], sv[MAXN];

int mx[MAXN * 4], lz[MAXN * 4];
void init(int u = 1, int lo = 1, int hi = n) {
    lz[u] = 0;
    if (lo == hi) {
        mx[u] = sv[lo];
    } else {
        int mid = lo + hi >> 1;
        init(u << 1, lo, mid);
        init(u << 1 ^ 1, mid + 1, hi);
        mx[u] = max(mx[u << 1], mx[u << 1 ^ 1]);
    }
}
void propo(int u) {
    if (lz[u] == 0) {
        return;
    }
    lz[u << 1] += lz[u];
    lz[u << 1 ^ 1] += lz[u];
    mx[u << 1] += lz[u];
    mx[u << 1 ^ 1] += lz[u];
    lz[u] = 0;
}
void incre(int s, int e, int x, int u = 1, int lo = 1, int hi = n) {
    if (lo >= s && hi <= e) {
        mx[u] += x;
        lz[u] += x;
        return;
    }
    propo(u);
    int mid = lo + hi >> 1;
    if (s <= mid) {
        incre(s, e, x, u << 1, lo, mid);
    }
    if (e > mid) {
        incre(s, e, x, u << 1 ^ 1, mid + 1, hi);
    }
    mx[u] = max(mx[u << 1], mx[u << 1 ^ 1]);
}

signed main()
{
        ios::sync_with_stdio(0), cin.tie(0);
        cin>>n>>q;
        rep(i,1,n+1){
            cin>>a[i];
        }
        rep(i,1,n+1){
            cin>>b[i];
        }
        rep(i,1,n){
            cin>>c[i];
        }

        int sma=0;
        for(int i=n;i>=1;i--){
            v[i]=a[i]-b[i];
            sv[i]=v[i]+sv[i+1];
            sma+=a[i];
        }
        

        init();

        while(q--){
            int p,x,y;int z;cin>>p>>x>>y>>z;
            sma-=a[p];
            incre(1,p,-v[p]);
            a[p]=x;
            b[p]=y;
            v[p]=a[p]-b[p];
            sma+=a[p];
            incre(1,p,v[p]);
            cout<<sma-max(0ll,mx[1])<<endl;
        }

    

    return 0;
}