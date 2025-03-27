#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int rand_int (int min, int max);
long long rand_longlong (long long min, long long max);

int main() {
	srand (time (0));
	freopen ("10.in", "w", stdout);

	int t = rand_int (15, 20); 
	cout << t << endl;
	for (int i = 0; i < t; ++ i) {
		int n = rand_int (15, 30);
		cout << n << endl;
		for (int j = 0; j < n; ++ j)
			cout << rand_longlong (536870912, 1073741824) << " ";
		cout << endl;
	}
	
	fclose (stdout);
	return 0;
}

int rand_int (int min, int max) {
	return (rand () % (max - min + 1) + min);
}

long long rand_longlong (long long min, long long max) {
	return (rand () % (max - min + 1) + min);
}
