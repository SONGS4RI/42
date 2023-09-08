/* 종이의 개수 */
/* 13:55 ~ 14:23 */
#include <iostream>
using namespace std;

int board[2200][2200], ans[3]={0,0,0};
void recur(int n, int x, int y)
{
	int err = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[x][y] != board[x+i][y+j]) // 만약 n x n을 탐색할때 다른부분이 존재한다면 err체크
			{
				err = 1;
				break;
			}
		}
		if(err) break;
	}
	if(!err) // 에러가 발생하지 않았다면
	{
		ans[board[x][y]+1]++; // ans[0]은 -1, ans[1] = 0, ans[2] = 1이므로
		return ;
	}
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			recur(n/3, x+(n/3)*i, y+(n/3)*j); // 9등분을 해서 재귀에 넣어준다.
	/* 매개변수로는 한변을 3등분한 n/3, 탐색의 첫위치는 처음에 받은 위치 + 나누어진 한변의 길이(n/3)*어느등분 위치인지이다 */
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin >> board[i][j];
	recur(n, 0, 0);
	cout << ans[0] << "\n" << ans[1] << "\n" << ans[2] << "\n";
}