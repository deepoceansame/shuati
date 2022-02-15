#include <iostream>
#include<cstdio>
#define ll long long
#define MAX 100002
using namespace std;

inline ll ls(ll x){
    return x<<1;
}

inline ll rs(ll x){
    return x<<1|1;
}

ll n,m, a[MAX];

struct tree
{
    int le, ri;
    ll ss, ta;
} t[4*MAX+2];

void build(ll p, ll le, ll ri)
{
    t[p].ta = 0;
    t[p].le = le;
    t[p].ri = ri;
    if(le==ri){
        t[p].ss = a[le];
        return; 
    }
    ll mid = le+ri>>1;
    build(ls(p), le, mid);
    build(rs(p), mid+1, ri);
    t[p].ss = t[ls(p)].ss + t[rs(p)].ss;
}

void spread(ll p){
    if(t[p].ta){
        t[ls(p)].ss += t[p].ta * (t[ls(p)].ri - t[ls(p)].le + 1);
        t[rs(p)].ss += t[p].ta * (t[rs(p)].ri - t[rs(p)].le + 1);
        t[ls(p)].ta += t[p].ta;
        t[rs(p)].ta += t[p].ta;
        t[p].ta=0;
     }
}

void update(ll p, ll fro, ll to, ll va)
{
    if(fro<=t[p].le && t[p].ri<=to){
        t[p].ss += va * (t[p].ri - t[p].le + 1);
        t[p].ta += va;
        return ;
    }
    spread(p);
    ll mid = t[p].le+t[p].ri>>1;
    if(fro<=mid) update(ls(p), fro, to, va);
    if(to>mid) update(rs(p), fro, to, va);
    t[p].ss = t[ls(p)].ss + t[rs(p)].ss;
}

ll query(ll p, ll fro, ll to)
{
    if(fro<=t[p].le && t[p].ri<=to){
        return t[p].ss;
    }
    spread(p);
    ll sum = 0;
    ll mid = t[p].le+t[p].ri>>1;
    if(fro<=mid) sum += query(ls(p), fro, to);
    if(to>mid) sum += query(rs(p), fro, to);
    return sum;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
    scanf("%d", &a[i]);
    build(1, 1, n);
    for(int i=1; i<=m; i++)
    {
        int ty, x, y, z;
        scanf("%d", &ty);
        if(ty==1){
            scanf("%d%d%d", &x, &y, &z);
            update(1, x, y, z);
        }
        else{
            scanf("%d%d", &x,&y);
            cout<<query(1,x,y)<<endl;
        }
    }
    return 0;
}





