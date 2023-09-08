/* 2xn 타일링 */
/* 13:02 ~ 13:23 */
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, dp[1001]={0,1,2};
	cin >> n;
	for(int i=3;i<=n;i++) dp[i] = (dp[i-2]%10007 + dp[i-1]%10007) % 10007;
	/* 피보나치 수열을 10007로 나누어준 나머지들을 저장해주면 된다. */
	cout << dp[n] << "\n";
}