/* 정수 삼각형 */
/* 14:13 ~ 14:28 */
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, dp[501][501], num;
	memset(dp,0,sizeof(dp));
	cin >> n;
	cin >> dp[0][1];
	for(int i=1;i<n;i++)
		for(int j=1;j<=i+1;j++)
		{
			cin >> num;
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + num;
		}
	for(int i=1;i<=n;i++) dp[n-1][0] = max(dp[n-1][i], dp[n-1][0]);
	cout << dp[n-1][0] << "\n";
}
/*
입력을 받을때 맨처음 앞뒤로 여분의 열을 만든다
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5 을

//arr//
i\j	0	1	2	3	4	5
0	0	7	0	0	0	0
1	0	3	8	0	0	0
2	0	8	1	0	0	0
3	0	2	7	4	4	0
4	0	4	5	2	6	5 처럼 받고
dp 배열에는 i-1열 j-1 과 j 의 dp값중 큰값을 골라 현재값과 더해 저장해준다.

//dp//
i\j	0	1	2	3	4	5
0	0	7	0	0	0	0
1	0	10	15	0	0	0
2	0	18	16	15	0	0
3	0	20	25	20	19	0
4	0	24	30	27	26	24
*/