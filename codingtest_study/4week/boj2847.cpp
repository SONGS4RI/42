/*게임을 만든 동준이*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	int arr[n],max_point,res=0;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	max_point = arr[n-1];//마지막 레벨 점수
	n--;
	while(--n>=0)
	{
		if(arr[n] >= max_point)//같거나 크면 마지막 점수보다 1작게끔
		{
			max_point--;
			res += arr[n] - max_point;
		}
		else
			max_point = arr[n];//작으면 max_point 조정
	}
	cout << res << "\n";
}