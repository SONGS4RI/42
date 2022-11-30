#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	long long n;
	cin >> n;
	
	long long start = 0, end = sqrt(n), mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (mid > sqrt(n)) end = mid - 1;
		else if(mid < sqrt(n))start = mid + 1;
		else break;
	}
	if (mid * mid == n) cout << mid;
	else cout << mid + 1;
}