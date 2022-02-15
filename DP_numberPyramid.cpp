#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

int n;
ll a[1001][1001];

inline ll getAnc1(int i, int j)
{
    // [i-1][j-1]
    if( (i-1)<0 || (j-1)<0){
        return 0;
    }
    else{
        return a[i-1][j-1];
    }
}

inline ll getAnc2(int i, int j){
    // [i-1][j]
    if( (i-1)<0 || j==i){
        return 0;
    }
    else{
        return a[i-1][j];
    }
}


int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            a[i][j] += max(getAnc1(i, j), getAnc2(i, j));
        }
    }

    int i = n-1;
    ll ans = 0;
    for (int j = 0; j <= i; j++)
    {
        ans = max(ans, a[i][j]);
    }
    cout<<ans<<endl;
    return 0;
    
}

