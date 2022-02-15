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

int mo;

struct tree
{
    int le, ri;
    ll ss, ta, ma;
} t[4*MAX+2];

void build(ll p, ll le, ll ri)
{
    t[p].ta = 0;
    t[p].ma = 1;
    t[p].le = le;
    t[p].ri = ri;
    if(le==ri){
        t[p].ss = a[le];
        t[p].ss %= mo;
        return; 
    }
    ll mid = le+ri>>1;
    build(ls(p), le, mid);
    build(rs(p), mid+1, ri);
    t[p].ss = (t[ls(p)].ss + t[rs(p)].ss)%mo;
}

void spread(ll p){
    if(t[p].ta!=0 || t[p].ma!=1){
        t[ls(p)].ss = (t[ls(p)].ss * t[p].ma)%mo;
        t[rs(p)].ss = (t[rs(p)].ss * t[p].ma)%mo;
        t[ls(p)].ss = (t[ls(p)].ss + t[p].ta * (t[ls(p)].ri - t[ls(p)].le + 1) )%mo;
        t[rs(p)].ss = (t[rs(p)].ss + t[p].ta * (t[rs(p)].ri - t[rs(p)].le + 1) )%mo;
        t[ls(p)].ta = (t[ls(p)].ta*t[p].ma + t[p].ta)%mo;
        t[rs(p)].ta = (t[rs(p)].ta*t[p].ma + t[p].ta)%mo;
        t[ls(p)].ma = (t[ls(p)].ma * t[p].ma)%mo;
        t[rs(p)].ma = (t[rs(p)].ma * t[p].ma)%mo;
        t[p].ta=0;
        t[p].ma=1;
     }
}

void updateAdd(ll p, ll fro, ll to, ll va)
{
    if(fro<=t[p].le && t[p].ri<=to){
        t[p].ss = (t[p].ss + va * (t[p].ri - t[p].le + 1))%mo;
        t[p].ta = (t[p].ta + va)%mo;
        return ;
    }
    spread(p);
    ll mid = t[p].le+t[p].ri>>1;
    if(fro<=mid) updateAdd(ls(p), fro, to, va);
    if(to>mid) updateAdd(rs(p), fro, to, va);
    t[p].ss = (t[ls(p)].ss + t[rs(p)].ss)%mo;
}

void updateMul(ll p, ll fro, ll to, ll va)
{
    if(fro<=t[p].le && t[p].ri<=to){
        t[p].ss = (t[p].ss * va)%mo;
        t[p].ma = (t[p].ma * va)%mo;
        t[p].ta = (t[p].ta * va)%mo;
        return ;
    }
    spread(p);
    ll mid = t[p].le+t[p].ri>>1;
    if(fro<=mid) updateMul(ls(p), fro, to, va);
    if(to>mid) updateMul(rs(p), fro, to, va);
    t[p].ss = (t[ls(p)].ss + t[rs(p)].ss)%mo;
}

ll query(ll p, ll fro, ll to)
{
    if(fro<=t[p].le && t[p].ri<=to){
        return t[p].ss;
    }
    spread(p);
    ll sum = 0;
    ll mid = t[p].le+t[p].ri>>1;
    if(fro<=mid) sum = (sum + query(ls(p), fro, to))%mo;
    if(to>mid) sum = (sum + query(rs(p), fro, to))%mo;
    return sum;
}

int main()
{
    int n, m;
    scanf("%d%d%d", &n, &m, &mo);
    for(int i=1; i<=n; i++)
    scanf("%d", &a[i]);
    build(1, 1, n);
    for(int i=1; i<=m; i++)
    {
        int ty, x, y, z;
        scanf("%d", &ty);
        if(ty==1){
            scanf("%d%d%d", &x, &y, &z);
            updateMul(1, x, y, z);
        }
        else if(ty==2){
            scanf("%d%d%d", &x, &y, &z);
            updateAdd(1, x, y, z);
        }
        else{
            scanf("%d%d", &x,&y);
            cout<<query(1,x,y)<<endl;
        }
    }
    return 0;
}





