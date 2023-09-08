/* 구간 합 구하기 4 */
/* 13:28 ~ 13:38 */
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,m,num,start,end,dp[100001]={0,};
	cin >> n >> m;
	cin >> dp[1];
	for(int i=2;i<=n;i++)
	{
		cin >> num;
		dp[i] = dp[i-1] + num; // 계속 더한값을 저장해준다.
	}
	for(int i=0;i<m;i++)
	{
		cin >> start >> end;
		cout << dp[end] - dp[start - 1] << "\n";
		/* end까지 더한값에서 start-1까지 더한값을 빼주는것은 곧 start ~ end 까지의 합과 같다. */
	}
}