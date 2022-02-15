#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
#define MAX 100002
const int mod = 99999997;
using namespace std;

int n;

struct matchs
{
    int hei;
    int ind;
} a[MAX], b[MAX];

int c[MAX];
int d[MAX];

bool cmp(matchs a, matchs b)
{
    return a.hei < b.hei;
}

ll merge(int la, int ra, int lb, int rb)
{
    int i = la;
    int j = lb;
    ll ans = 0;
    int k = la;
    while(k<=rb){
        if((c[i]<=c[j]&&i<lb) || j>rb){
            d[k]=c[i];
            i++;
            k++;
        }
        else{
            d[k]=c[j];
            if(i<lb){
                ans=(ans+(ra-i+1))%mod;
            }
            j++;
            k++;
        } 
    }
    for(int i=la; i<=rb; i++){
        c[i] = d[i];
    }
    return ans;
}

ll sortAndGetAns(int le, int ri)
{
    if(ri<=le){
        return 0;
    }
    int mi = le+ri>>1;
    ll ans = 0;
    ans = (ans + sortAndGetAns(le, mi))%mod;
    ans = (ans + sortAndGetAns(mi+1, ri))%mod;
    ans = (ans + merge(le, mi, mi+1, ri))%mod;
    return ans;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i].hei);
        a[i].ind = i;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i].hei);
        b[i].ind = i;
    }
    sort(a, a+n, cmp);
    sort(b, b+n, cmp);
    for(int i=0;i<n;i++){
        c[b[i].ind] = a[i].ind;
    }
    ll ans = sortAndGetAns(0, n-1);
    cout << ans;
    return 0;
}