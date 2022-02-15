#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;

int a, b, p;
ll fastPower(int a, int b, int p)
{   
    if (b==1)
    {
        return a;
    }
    
    ll ans = 1;
    ll an = fastPower(a, b/2, p) % p;
    ans = ( ans * an )%p;
    ans = ( ans * an )%p;
    if(b&1){
        ans = (ans * a)%p;
    }
    return ans;
}

int main()
{
    scanf("%d%d%d", &a, &b, &p);
    ll ans = fastPower(a, b ,p);
    cout << a << '^' << b << " mod " << p << '=' << ans;
}


// #include<cstdio>
// long long B,P,K;
// long long qpow(int base,int p){
// 	long long ans=1,tmp=base;//从底数开始乘，不停自乘
// 	while(p!=0){//指数不是0 
// 		if(p&1){
// 			ans=(ans%K*tmp%K)%K;
// 		} 
// 		tmp=(tmp%K*tmp%K)%K;//自乘
// 		p=p>>1;//访问下一位 
// 	} 
// 	ans=ans%K;
// 	return ans;
// } 
// int main(){
// 	scanf("%lld%lld%lld",&B,&P,&K);
// 	long long ans=qpow(B,P);
// 	ans=ans%K;
// 	printf("%lld^%lld mod %lld=%lld",B,P,K,ans);
// 	return 0;
// }
