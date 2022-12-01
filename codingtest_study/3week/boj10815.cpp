/*숫자카드*/

#include <bits/stdc++.h>
using namespace std;

int compare(const void *a, const void *b)
{
	const int *A = (int *)a;
	const int *B = (int *)b;

	return (*A-*B);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m,n,num;

	cin >> m;
	int arr[m];
	for(int i=0;i<m;i++)
		cin >> arr[i];
	qsort(arr,m,sizeof(int),compare);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> num;
		int *ptr = (int *)bsearch(&num,arr,sizeof(arr)/sizeof(int),sizeof(int),compare);//bsearch�� ����Ž�� �����Լ��̴�.
		if(ptr) cout << 1;
		else cout << 0;
		cout << " ";
	}
}