/* 이친수 */
/* 14:31 ~ 14:39 */
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	long long n, dp[91]={0,1,1};
	cin >> n;
	for(int i=3;i<=n;i++) dp[i] = dp[i-1] + dp[i-2];
	cout << dp[n] << '\n';
}