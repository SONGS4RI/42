/* 동전 0 */
/* 13:58 ~ 14:25 */
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n,k,arr[10],res=0;
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> arr[i];
	while(k)
	{
		for(int i=n-1;i>=0;i--)
		{
			if(arr[i]<=k)
			{
				res += k/arr[i];
				k %= arr[i];
				break;
			}
		}
	}
	cout << res << "\n";
}