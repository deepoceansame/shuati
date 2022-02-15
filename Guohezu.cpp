#include <iostream>
#include <cstring>
#define ll long long

using namespace std;

///https://www.luogu.com.cn/problem/P1002

int main()
{
	int bx, by, mx, my;
	cin >> bx >> by >> mx >> my;
	bool isblock[40][40] = {0};
	ll stage[40][40];
	const int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2, 0 };
	const int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1, 0 };
	bx = bx + 2;
	by = by + 2;
	mx = mx + 2;
	my = my + 2;
	memset(stage, 0, sizeof(stage));
	for (int i = 0; i < 9; i++) {
		isblock[mx + dx[i]][my + dy[i]] = true;
	}
	stage[2][1] = 1;
	for (int y = 2; y <= by; y++) {
		for (int x = 2; x <= bx; x++) {
			if (isblock[x][y]) continue;
			stage[x][y] = stage[x - 1][y] + stage[x][y - 1];
		}
	}
	cout << stage[bx][by] << endl;
	return 0;
}