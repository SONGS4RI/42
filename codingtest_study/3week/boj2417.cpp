/* 정수제곱근 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	long long n;
	cin >> n;
	long long left=0, right = n, mid;
	while(left<=right)
	{
		mid = (left+right)/2;
		if(mid*mid < n && mid <= sqrt(__LONG_LONG_MAX__)) left = mid+1;
		else right = mid -1;
	}
	cout << left;
}