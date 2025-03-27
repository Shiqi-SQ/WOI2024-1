#include <iostream>
#include <cstring>
using namespace std;

int main () {
	int l; string t;
	cin >> l >> t;
	for (int i = l - 1; i >= 0; -- i) 
		cout << t[i];
	return (0);
}
