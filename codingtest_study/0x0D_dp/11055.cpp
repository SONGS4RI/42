/* 가장 큰 증가 부분 수열 */
/* 15:43 ~ */
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
		if (arr[i]<arr[i-1])
		{
			for(int j=i-1;j>=0;j--)
				if (arr[j]<arr[i])
				{
					dp[i] = dp[j] + arr[i];
					break;
				}
			if (!dp[i]) dp[i] = arr[i];
		}
		else
			dp[i] = dp[i-1] + arr[i];
		res = max(res, dp[i]);
	}
	for(int i=0;i<n;i++) cout << dp[i] << " ";
	cout << "\n" << res << "\n";
}
/*

arr : 1 100   2  50   60 3  5  6  7  8
dp	: 1 101   3  53  113 6 11 17 24 32
res : 1 101 101 101  113 ...


5
1 23 3 4 10

*/