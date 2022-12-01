/* 정수제곱근 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	long long n;
	cin >> n;
	long long start = 0, end = n, mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (mid >= (n / mid)) end = mid - 1;
		else if(mid < (n / mid)) start = mid + 1;
	}
	if (mid * mid == n) cout << mid;
	else cout << mid + 1;
	cout.precision(15);
	cout << "\nsqrt(n) : " << sqrt(n);
}