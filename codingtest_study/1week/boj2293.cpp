#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int arr[n+1], dp[k+1] = {1, };
    for(int i=1;i<=n;i++) cin >> arr[i];

    for(int i=1; i<=n; i++)
    {
        for(int j=arr[i];j<=k;j++)
            dp[j] = dp[j] + dp[j-arr[i]];
    }
    cout << dp[k] << "\n";
}