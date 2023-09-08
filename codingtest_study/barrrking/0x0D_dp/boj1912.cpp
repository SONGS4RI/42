/* 연속합 */
/* 14:43 ~  15:26 */
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, res;
	cin >> n;
	int arr[n],dp[n];
	for(int i=0;i<n;i++) cin >> arr[i];
	dp[0] = arr[0];
	res = arr[0];
	for(int i=1;i<n;i++)
	{
		dp[i] = max(dp[i-1] + arr[i], arr[i]); // (이전까지의 합 + 현재 값), (현재 값) 중 큰값을 저장
		res = max(res,dp[i]); // 최대값 갱신
	}
	cout << res << "\n";
}
/* 예시
arr : 10 -4  3  1  5  6 -35 12 21 -1
dp	: 10  6  9 10 15 21 -14 12 33 32
res	: 10 10 10 10 15 21  21 21 33 33
*/