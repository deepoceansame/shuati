#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

//https://www.luogu.com.cn/problem/P1102

int main()
{
	int n, c;
	cin >> n >> c;
	ll ans = 0;
	int a[200001];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i = 0; i < n; i++)
	{
		ans += (upper_bound(a, a+n, a[i]+c)) - lower_bound(a, a+n, a[i]+c);
	}
	cout << ans;
	return 0;
}