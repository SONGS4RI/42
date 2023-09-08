/* 가장 긴 증가하는 부분 수열 */
/* 16:14 ~ 17:40 */
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,dp[1000], arr[1000],res=1;
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	fill(dp,dp+n,1);
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
			if(arr[j]<arr[i]) dp[i] = max(dp[j]+1, dp[i]);
		res = max(res,dp[i]);
	}
	cout << res << "\n";
}
/*
	간단하게 dp에 현재 수를 포함한 가장 긴 수열의 길이를 저장한다.
	이전값들을 탐색하면서 값이 더작으면 그때의 dp+1값과
	현재 dp값을 비교해 긴값을 저장하면된다.
*/