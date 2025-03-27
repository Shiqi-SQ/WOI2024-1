#include <iostream>
using namespace std;

int modNum = 1000007;

int f[101][101] = {};

int main () {
	int n, m, t; cin >> n >> m;
	for (int i = 0; i < n + 1; ++ i) 
		f[i][0] = 1;
	for (int i = 1; i < n + 1; ++ i) {
		cin >> t;
		for (int j = 0; j < t + 1; ++ j) {
			for (int k = 0; k < m - j + 1; ++ k) {
				if ((j == 0) && (k == 0)) continue;
				f[i][j + k] += f[i - 1][k];
				f[i][j + k] %= modNum;
			}
		}
	}
	cout << f[n][m] % modNum;
	return (0);
}
