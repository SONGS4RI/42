/* 색종이 만들기 */
/* 14:35 ~  14:40 */
#include <iostream>
using namespace std;
int board[128][128], ans[2]={0,};
void recur(int n, int x, int y)
{
	int err = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[x][y] != board[x+i][y+j]) // n x n에서 다른색이 있으면 err체크
			{
				err = 1;
				break;
			}
		}
		if(err) break;
	}
	if(!err) // 같은 색이면
	{
		ans[board[x][y]]++;
		return ;
	}
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++) recur(n/2, x+(n/2)*i, y+(n/2)*j); // 4등분해서 재귀
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
	cout << ans[0] << "\n" << ans[1] << "\n";
}