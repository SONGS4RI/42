#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,res,x,y,num=0;
	int xcor[4] = {1,0,-1,0}, ycor[4] = {0,-1,0,1}; //동서남북 방향용
	pair<int,int> cor;//좌표 출력 저장용
	cin >> n >> res;
	int arr[n][n];

	x = n/2; y = n/2;// 시작좌표는 항상 고정이다
	for(int i=1;i<=n*n;i++)
	{
		if(i == pow(num+1,2))//홀수의 제곱일때가 항상 달팽이 모양으로 돌았을때의 종료지점
		{
			num+=2;
			arr[x][y] = i++;
			y++;
		}
		for(int j=0;j<4;j++)
			for(int k=0;k<num;k++)	
			{
				x += xcor[j];
				y += ycor[j];
				arr[x][y] = i++;
			}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			// if(arr[i][j] == res)
			// {
			// 	cor.first = i;
			// 	cor.second = j;
			// }
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}
	// cout << cor.first << " " << cor.second;
}
