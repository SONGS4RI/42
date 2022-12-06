/* аж╫д */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t,n,mx;
	long long res;
    cin >> t;
    while (t--)
    {
		cin >> n;
		int arr[n] = {0,};
        mx = 0;
        res = 0;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = n-1; i >= 0; i--)
        {
            mx = max(mx, arr[i]);
            res += mx - arr[i];
        }
        cout << res << "\n";
    }
}