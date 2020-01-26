//https://atcoder.jp/contests/joi2020yo2/tasks/joi2020_yo2_d
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int m, e, b[10][10], dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};
bool v[13][100005];
struct st {
	int r, c, s, cnt;
};
queue<st> qu;
void f(st p) {
	int z;
	z = b[p.r][p.c];
	if (v[z][p.s]) return;
	v[z][p.s] = 1;
	qu.push(p);
}

int main()
{
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif    
	int i, j, t1, t2, tr, tc, z;
	st t;
	cin >> m >> e;
	memset(b, -1, sizeof(b));
	b[1][1] = 7;
	b[1][2] = 8;
	b[1][3] = 9;
	b[2][1] = 4;
	b[2][2] = 5;
	b[2][3] = 6;
	b[3][1] = 1;
	b[3][2] = 2;
	b[3][3] = 3;
	b[4][1] = 0;
	f({4, 1, 0, 0});
	while (!qu.empty()) {
		t = qu.front(); qu.pop();
		if (t.s == e) {
			cout << t.cnt << endl;
			return 0;
		}
		for (i = 0;i < 4; i++) {
			tr = t.r + dr[i];
			tc = t.c + dc[i];
			if (b[tr][tc] != -1) f({tr, tc, t.s, t.cnt + 1});
		}
		z = b[t.r][t.c];
		f({t.r, t.c, (t.s * 10 + z) % m, t.cnt + 1});
	}
    return 0;
}
