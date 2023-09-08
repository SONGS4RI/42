/* RGB거리 */
/* 15:10 ~ 15:33 */
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	int arr[n][3], dp[n][3];
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++) cin >> arr[i][j];
	dp[0][0] = arr[0][0]; dp[0][1] = arr[0][1]; dp[0][2] = arr[0][2];
	for(int i=1;i<n;i++)
		for(int j=0;j<3;j++)
			dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + arr[i][j]; // 이와같은 점화식 도출
	cout << min(min(dp[n-1][0] ,dp[n-1][1]) ,dp[n-1][2]) << "\n";
}