/*������ ���� ������*/
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
	max_point = arr[n-1];//������ ���� ����
	n--;
	while(--n>=0)
	{
		if(arr[n] >= max_point)//���ų� ũ�� ������ �������� 1�۰Բ�
		{
			max_point--;
			res += arr[n] - max_point;
		}
		else
			max_point = arr[n];//������ max_point ����
	}
	cout << res << "\n";
}