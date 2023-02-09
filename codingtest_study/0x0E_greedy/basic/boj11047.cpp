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
			if(arr[i]<=k) // 가장 큰수부터 확인해서 목표값보다 작은값을 찾으면
			{
				res += k/arr[i]; // 나눈값 더하기
				k %= arr[i]; // 나머지를 목표값으로 바꿔주기
				break;
			}
		}
	}
	cout << res << "\n";
}