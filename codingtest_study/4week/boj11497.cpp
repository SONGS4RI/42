/* 통나무 건너뛰기 */
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t,n;
	cin >> t;
	while(t--)
	{
		int ans=0;
		cin >> n;
		int arr[n];
		for(int i = 0 ;i < n;i++) cin>> arr[i];

		sort(arr,arr+n);
		for(int i = 0 ; i <n-2 ;i++)
			ans = max(arr[i+2]-arr[i], ans);
		cout<< ans << "\n";
	}
}