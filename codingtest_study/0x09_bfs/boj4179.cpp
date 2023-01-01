/* 불! */
/* 17:18 ~ */
#include <iostream>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int board[2][1000][1000];
int r,c;

void bfs(queue<pair<int,int>> q,int idx)
{
	int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
	while(q.size())
	{
		pair<int,int> p = q.front();
		q.pop();
		for(int dir=0;dir<4;dir++)
		{
			int nx = p.first + dx[dir];
			int ny = p.second + dy[dir];
			if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
			if(board[idx][nx][ny] != 0) continue;
			board[idx][nx][ny] = board[idx][p.first][p.second] + 1;
			q.push({nx,ny});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> r >> c;
	memset(board,-1,sizeof(board));
	char ch;
	queue<pair<int,int>> q_j,q_f;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			cin >> ch;
			if(ch == 'J')
			{
				board[0][i][j] = 1;//사람
				q_j.push({i,j});
			}
			else if(ch == 'F')
			{
				board[1][i][j] = 1;//불
				q_f.push({i,j});
			}
			else if(ch == '.')
			{
				board[0][i][j] = 0;
				board[1][i][j] = 0;
			}
		}
	bfs(q_j,0);
	bfs(q_f,1);
	int ans = INT32_MAX;
	for(int i=0;i<c;i++)
	{
		if(board[0][0][i] < board[1][0][i]) ans = min(ans,board[0][0][i]);
		if(board[0][r-1][i] < board[1][r-1][i]) ans = min(ans,board[0][r-1][i]);
	}
	for(int i=0;i<r;i++)
	{
		if(board[0][i][0] < board[1][i][0]) ans = min(ans,board[0][i][0]);
		if(board[0][i][c-1] < board[1][i][c-1]) ans = min(ans,board[0][i][c-1]);
	}
	if(ans == INT32_MAX) cout << "IMPOSSIBLE\n";
	else cout << ans << "\n";
}