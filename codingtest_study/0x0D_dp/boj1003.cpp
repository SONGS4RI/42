/* 피보나치 함수 */
/* 14:08 ~ 14:23 */
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t,n, dp[42]={1,0,1,};
	for(int i=3;i<=41;i++)
		dp[i] = dp[i-1] + dp[i-2];
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << dp[n] << " " << dp[n+1] << "\n";
	}
}
/*
	간단히 0을 출력하는 횟수는 1,0,1,1,2,4,....
	1을 출력하는 횟수는 0,1,1,2,4......로 한칸씩 밀려있다.
	수가 n일때 dp[n] 이 0의 횟수 dp[n+1]이 1의 횟수이다.
*/