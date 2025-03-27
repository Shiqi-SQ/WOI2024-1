#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	double time;
	int id;
} node;

bool cmp (node a, node b) {
	return ( a.time < b.time);
}

int main () {
	int n;
	cin >> n;
	node peo[1004];
	for (int i = 0; i < n; ++ i) {
		cin >> peo[i].time;
		peo[i].time += 1;
		peo[i].id = i + 1;
	}
	double tot = 0;
	for (int i = 0; i < n; ++ i) {
		stable_sort (peo + i, peo + n, cmp);
		cout << peo[i].id << " ";
		peo[i].time *= (n - i - 1);
        tot += peo[i].time;
	}
	cout << endl;
	tot /= n;
	cout << int (tot);
	return 0;
}
