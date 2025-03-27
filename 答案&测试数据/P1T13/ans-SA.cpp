#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF 2147483647

int n, ans = INF, a[1005];

int get ();
void SA ();

int main() {
	srand (rand ());
	int T;
	cin >> T;
	while (T --) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int ctrl = 1000;
		while (ctrl --) SA ();
		cout << ans << endl;
		ans = INF;
	}
}

int get () {
	int sum1 = 0, sum2 = 0;
	for (register int i = 1; i <= (n + 1) / 2; ++ i)
		sum1 += a[i];
	for (register int i = (n + 1) / 2 + 1; i <= n; ++ i)
		sum2 += a[i];
	return abs (sum1 - sum2);
}

void SA () {
	double beginT = 10000, endT = 1e-10, changeT = 0.9112;
	for (register double T = beginT; T > endT; T *= changeT) {
		int x = rand () % n + 1, y = rand () % n + 1;
		swap (a[x], a[y]);
		int sum = get ();
		if (sum < ans)
			ans = sum;
		else if (exp ((ans - sum) / T) < (double (rand ()) / RAND_MAX))
			swap (a[x], a[y]);
	}
}
