/* 1로 만들기 2 */
/* 13:05 ~ 13:25 */

#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, dp[1000001]={0,};
	cin >> n;
	for(int i=2;i<=n;i++)
	{
		if (i%6==0) dp[i] = min(min(dp[i/3],dp[i/2]),dp[i-1])+1; // 6으로 나누어지면
		else if(i%3==0) dp[i] = min(dp[i/3], dp[i-1])+1; // 3으로
		else if(i%2==0) dp[i] = min(dp[i/2], dp[i-1])+1; // 2로
		else dp[i] = dp[i-1]+1;
	}
	cout << dp[n] << "\n";
	for(int i=n;i>=1;) // 역순으로
	{
		cout << i << " ";
		if (i%3 == 0 && dp[i] == dp[i/3]+1) i /= 3;
		else if (i%2 == 0 && dp[i] == dp[i/2]+1) i /= 2;
		else i--;
	}
}