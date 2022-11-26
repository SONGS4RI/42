#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,res,x,y,num = 2;
	int xcor[4] = {0, 1, 0, -1}, ycor[4] = {1, 0, -1, 0}; //동서남북 방향용
	pair<int,int> cor;//좌표 출력 저장용
	cin >> n >> res;
	int arr[n][n];

	x = n / 2; y = n / 2;// 시작좌표는 항상 고정이다
	arr[x][y] = 1;
	for(int i=2; i<=n*n;)
	{
		x--;
		for(int j=0;j<num-1;j++)// 동쪽일때 만 예외를 준다
			arr[x][y++] = i++;
		arr[x][y] = i++;
		for(int j=1; j<4; j++)
		{
			for(int k=0;k<num;k++)	
			{
				x += xcor[j];
				y += ycor[j];
				arr[x][y] = i++;
			}
		}
		num+=2;// 중심에서 몇번째 원인지에 따라 변경해주어야 한다.
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j] == res)
			{
				cor.first = i + 1;
				cor.second = j + 1;
			}
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}
	cout << cor.first << " " << cor.second;
}
