/* 유기농 배추 */
/* 13:55 ~ 14: */
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t,m,n,k,nx,ny;
	int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
	cin >> t;
	while(t--)
	{
		cin >> m >> n >> k;
		int ans = 0;
		int board[n][m]; memset(board,0,sizeof(board));
		queue<pair<int,int> > q;
		for(int i=0;i<k;i++)
		{
			cin >> nx >> ny;
			board[nx][ny] = 1;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(board[i][j]==1)
				{
					q.push(make_pair(i,j));
					board[i][j] = 2;
					while(q.size())
					{
						pair<int,int> cur = q.front();
						q.pop();
						for(int dir=0;dir<4;dir++)
						{
							nx = cur.first + dx[dir];
							ny = cur.second + dy[dir];
							if(nx<0 || ny<0 || nx>=n || ny>= m) continue;
							if(board[nx][ny]!=1) continue;
							q.push(make_pair(nx,ny));
							board[nx][ny] = 2;
						}
					}
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}