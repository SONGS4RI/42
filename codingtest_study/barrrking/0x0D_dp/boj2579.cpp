/*  계단 오르기 */
/* 14:43 ~ 15:08*/
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	int arr[n], dp[n];
	for(int i=0;i<n;i++) cin >> arr[i];
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	if(n<=2)
	{
		cout << dp[n-1] << "\n";
		return (0);
	}
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for(int i=3;i<n;i++) dp[i] = max(dp[i-2] + arr[i], dp[i-3]+arr[i-1]+arr[i]); // 핵심 점화식
	/* i번째의 계단에서 최대값은 i-2번째까지의 최대값 + i계단값, i-3번째까지의 최대값 + i-1번 계단값 + i계단값 중 큰값이다.*/
	cout << dp[n-1] << "\n";
}