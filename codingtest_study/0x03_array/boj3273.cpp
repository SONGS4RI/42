/* 두 수의 합 */
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, num, ans=0;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) cin >> arr[i];
	cin >> num;
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
	{
		int idx;
		idx = lower_bound(arr,arr+n,num-arr[i]) - arr;
		if(arr[i] + arr[idx] == num && i != idx)
			ans++;
	}
	cout << ans/2 << "\n";
}