/* 방 배정 */
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,k,a,b,ans=0;
	cin >> n >> k;
	int arr[7][2];
	memset(arr,0,sizeof(arr));
	for(int i=0;i<n;i++)
	{
		cin >> b >> a;
		arr[a][b]++;
	}
	for(int i=1;i<=6;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(arr[i][j]!=0)
			{
				if(arr[i][j]%k == 0) ans += arr[i][j]/k;
				else ans += arr[i][j]/k + 1;
			}
		}
	}
	cout << ans << "\n";
}