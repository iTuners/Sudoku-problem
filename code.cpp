#include<iostream>
using namespace std;
int m[9][9],f[9][9];
int cnt[1 << 9];
int num[1 << 8 + 1];
int a[9], b[9], c[9];
int tot;
void change(int x, int y, int v) {
	a[x] ^= v;
	b[y] ^= v;
	c[f[x][y]] ^= v;
}
bool dfs(int n) {
	if (n == tot + 1)
		return true;
	int x, y, minv = 10, state;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (m[i][j] != 0) continue;
			state = a[i] & b[j] & c[f[i][j]];
			if (cnt[state] == 0) return false;
			if (cnt[state] < minv) {
				minv = cnt[state];
				x = i; y = j;
			}
		}
	 }
	state = a[x] & b[y] & c[f[x][y]];
	for (; state; state -= state & -state) {
		int k = state & -state;
		m[x][y] = num[k];
		change(x, y, k);
		if (dfs(n + 1)) return true;
		change(x, y, k);
		m[x][y] = 0;
	}
	return false;
}
void work(void) {
	for (int i = 0; i < 9; i++)
		a[i] = b[i] = c[i] = (1 << 9) - 1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> m[i][j];
			if (m[i][j] == 0) tot++;
			else change(i, j, 1 << (m[i][j] - 1));
		}
	}
	dfs(1);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		num[1 << i] = i + 1;
	}
	for (int i = 0; i < (1 << 9); i++) {
		for (int j = i; j; j -= j & -j) {
			cnt[i]++;
		}
	}
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			f[i][j] = i / 3 * 3 + j / 3;
	work();
}
