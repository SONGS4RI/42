#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) cin >> arr[i];
	int dp[n] = {arr[0], }, res = dp[0];

	for(int i=1;i<n;i++)
	{
		dp[i] = max(dp[i-1] + arr[i],arr[i]);
		res = max(res, dp[i]);
	}
	cout << res << "\n";
}