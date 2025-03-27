#include <iostream>
using namespace std;

int main () {
	int n, t, max = 0; cin >> n;
	for (int i = 0; i < n; ++ i) {
		cin >> t;
		if (t > max) {
			max = t;
		}
	}
	cout << max;
	return (0);
}
