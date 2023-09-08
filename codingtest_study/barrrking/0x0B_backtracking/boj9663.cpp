/* N-Queen */
/* 14:50 ~ 15:11 */
#include <iostream>
using namespace std;
int n,board[15]={0,},ans=0;

void dfs(int cnt)
{
	if(cnt == n) // 놓은 퀸수가 n과 같다면
	{
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		int err = 0;
		for(int j=0;j<cnt;j++)
			if(board[j]==i || cnt-j==abs(i-board[j])) // 이전에 놓은 퀸이 현재 i값과 같은지(가로가 겹치는지 판별) || 대각으로 만날수 있는지
			{
				err = 1;
				break ; // 생각보다 해주고 안해주고의 계산시간 차이가 크다
			}
		if(err) continue; // 퀸끼리 경로에 있게된다면 넘긴다.
		board[cnt] = i; // 보드에 해당 i값을 넣어주고
		dfs(cnt+1); // 카운트 하나 한값을 넘겨준다.
	}
}

int main()
{
	cin >> n;
	dfs(0);
	cout << ans << "\n";
}