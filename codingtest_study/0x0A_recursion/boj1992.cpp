/* 쿼드트리 */
/* 14:47 ~ 14:57 */
#include <iostream>
#include <string>
using namespace std;

string board[64];

void recur(int n, int x, int y)
{
	int err = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[x][y]!=board[x+i][y+j])
			{
				err = 1;
				break;
			}
		}
	}
	if(!err)
	{
		cout << board[x][y];
		return ;
	}
	cout << "("; // 재귀탈때 구분해주는 용
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++) recur(n/2, x+(n/2)*i, y+(n/2)*j); // 상좌, 상우, 하좌,하우 순으로 잘넣자
	cout << ")";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> board[i];
	recur(n,0,0);
	cout << "\n";
}