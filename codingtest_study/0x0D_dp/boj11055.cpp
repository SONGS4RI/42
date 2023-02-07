/* 가장 큰 증가 부분 수열 */
/* 15:43 ~ 16:38 */
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, dp[1000]={0,}, arr[1000], res;
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	dp[0] = arr[0];
	res = arr[0];
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
			if (arr[j]<arr[i])
				dp[i] = max(dp[j] + arr[i], dp[i]);
			// 값을 찾았다고 바로 break하면 더큰값이 존재할 수도 있기때문에 맨처음까지 다 탐색해준다.
		if (!dp[i]) dp[i] = arr[i];
		res = max(res, dp[i]);
	}
	cout << res << "\n";
}
/*

10
2 11 3 14 1 200 100 5 101 13
=> 228

20 481
97 112 16 129 25 87 15 75 85 65 117 143 133 83 59 30 111 24 70 128
=> 481

5
1 3 3 2 3
=> 6

*/