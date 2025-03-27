#include <iostream>
using namespace std;

#define M 5800005
#define M1 100000005

bool f[M1];
int n, cnt = 0, p[M];
int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (!f[i]) p[++cnt] = i;
		for (int j = 1; j <= cnt; j++) {
			if (i * p[j] > n) break;
			f[i * p[j]] = 1;
			if (!(i % p[j])) break;
		}
	}
	cout << cnt;
	return 0;
}
