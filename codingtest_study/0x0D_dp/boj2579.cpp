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
	for(int i=3;i<n;i++) dp[i] = max(dp[i-2] + arr[i], dp[i-3]+arr[i-1]+arr[i]);
	cout << dp[n-1] << "\n";
}