#include <iostream>
#include<cstdio>
#define ll long long
#define MAX 500002
using namespace std;

 int n, a[MAX], b[MAX];

ll merge(int la, int ra, int lb, int rb)
{
    int i = la;
    int j = lb;
    ll ans = 0;
    int k = la;
    while(k<=rb){
        if((a[i]<=a[j]&&i<lb) || j>rb){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            if(i<lb){
                ans+=(ra-i+1);
            }
            j++;
            k++;
        } 
    }
    for(int i=la; i<=rb; i++){
        a[i] = b[i];
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
    ans+=sortAndGetAns(le, mi);
    ans+=sortAndGetAns(mi+1, ri);
    ans+=merge(le, mi, mi+1, ri);
    return ans;
}

int main()
{
   scanf("%d", &n);
   for(int i=0;i<n;i++){
       scanf("%d", &a[i]);
   }
   cout << sortAndGetAns(0, n-1);
}
