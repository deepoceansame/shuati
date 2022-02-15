#include <iostream>
#include<cstdio>
#define ll long long
#define MAX 100002
using namespace std;

int n, a[MAX];

void insertSort(int le, int ri){
    for (int i = le+1; i <= ri; i++)
    {
        int j=i;
        while(j>le&&a[j]<a[j-1]){
            swap(a[j], a[j-1]);
            j--;
        }
    }
    
}

void qsort(int le, int ri)
{
    if ((ri-le)<6){
        insertSort(le, ri);
        return;
    }
    int i = le;
    int j = ri;
    int pivot = a[le]; 
    while(i!=j){
        while(j>i && a[j]>=pivot){
            j --;
        }
        a[i] = a[j];
        while(i<j && a[i]<=pivot){
            i ++;
        }
        a[j] = a[i];
    }
    a[i] = pivot;
    qsort(le, i);
    qsort(i+1, ri);
}


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}