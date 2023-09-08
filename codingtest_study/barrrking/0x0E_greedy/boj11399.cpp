/* ATM */
/* 12:02 ~ 12:12 */
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,arr[1000],res=0;
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	sort(arr, arr+n);
	// 오름차순 정렬을 해주는 이유는 인출시간이 적은사람 순으로 줄을 서야
	// 다음사람이 기다리는 시간도 적게 들기 떄문이다.
	for(int i=0;i<n;i++) res += arr[i]*(n-i); // 해당 인출시간동안 기다리는 시간 + 인출시간
	cout << res << "\n";
}