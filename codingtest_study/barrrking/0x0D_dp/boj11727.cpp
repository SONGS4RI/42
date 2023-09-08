/* 2xn 타일링 2 */
/* 14:11 ~ 14:32 */
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,dp[1001]={0,1,3,}; // 0 1 3 5 11 21 .... 과같은 수열이 만들어진다.
	cin >> n;
	for(int i=3;i<=n;i++)
		dp[i] = (dp[i-1]+dp[i-2]*2)%10007;
	cout << dp[n] << "\n";
}