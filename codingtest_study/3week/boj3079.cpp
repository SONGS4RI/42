/* 입국심사 */
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e5;
long long times[MAX];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)	cin >> times[i];
	sort(times, times + N);

	long long low = 0, high = M * times[N - 1];
	long long res = M * times[N - 1];

	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long sum = 0;

		for (int i = 0; i < N; i++)	sum += mid / times[i];// 2 3 3 4 6 8 9
		if (sum >= M)
		{
			res = min(res, mid);
			high = mid - 1;
		}
		else low = mid + 1;
	}
	cout << res << "\n";
}