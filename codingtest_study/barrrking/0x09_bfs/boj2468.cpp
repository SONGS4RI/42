/* 안전 영역 */
/* 13:27 ~ 13:51*/
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,ans=1,nx,ny,idx_min=100,idx_max=0;
	int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
	cin >> n;
	int board[n][n];
	pair<int,int> cur;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin >> board[i][j];
			idx_min = min(idx_min,board[i][j]); // 물에 잠기는 시작점 체크
			idx_max = max(idx_max,board[i][j]); // 최대높이 지역 체크
		}
	for(int idx=idx_min;idx<idx_max;idx++)// 물이 하나도 안잠겼을때는 당연히 답이 1이므로, 잠기는 시작점부터 최대높이전까지 탐색
	{
		queue<pair<int,int>> q; // 초기화 필수
		bool visited[n][n]; memset(visited,false,sizeof(visited)); // 잠기는 높이가 바뀌기때문에 초기화를 해주어야한다.
		int cnt = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j]>idx && !visited[i][j])
				{
					visited[i][j] = true;
					q.push({i,j});
					while(!q.empty())
					{
						cur = q.front();
						q.pop();
						for(int dir=0;dir<4;dir++)
						{
							nx = cur.first + dx[dir];
							ny = cur.second + dy[dir];
							if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
							if(visited[nx][ny] || board[nx][ny]<=idx) continue;
							visited[nx][ny] = true;
							q.push({nx,ny});
						}
					}
					cnt++;
				}
			}
		}
		ans = max(ans,cnt); // 최대값 비교
	}
	cout << ans << "\n";
}