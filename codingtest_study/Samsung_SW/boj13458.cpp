#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, b, c;
	long long answer=0;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;

	for (int i=0; i<n; i++) {
		a[i] = a[i] - b >= 0 ? a[i] - b : 0;
		answer += a[i] % c ? a[i] / c + 2 : a[i] / c + 1;
	}

	cout << answer;
}