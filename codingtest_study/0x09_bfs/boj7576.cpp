/* 토마토 */
/* 15:32 ~  15:52*/
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int m,n,ans=0;
	int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
	cin >> m >> n;
	int board[n][m];
	queue<pair<int,int>> q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 1) q.push({i,j});
		}
	while(q.size())
	{
		pair<int,int> p = q.front();
		q.pop();
		for(int dir=0;dir<4;dir++)
		{
			int nx = p.first + dx[dir];
			int ny = p.second + dy[dir];
			if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
			if(board[nx][ny]) continue;
			board[nx][ny] = board[p.first][p.second] + 1;
			q.push({nx,ny});
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			ans = max(ans,board[i][j]);
			if(!board[i][j])
			{
				cout << "-1\n";
				exit(0);
			}
		}
	cout << ans-1 << "\n";
}