/* 상범 빌딩 */
/* 14:30 ~ 14:55 */
#include <iostream>
#include <queue>
#include <string.h>
#include <tuple>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int l,r,c,nx,ny,nz;
	int dx[6] = {-1,0,1,0,0,0}, dy[6] = {0,1,0,-1,0,0}, dz[6] = {0,0,0,0,1,-1}; // 3차원 이동방향
	tuple<int,int,int> cur;
	while(1)
	{
		cin >> l >> r >> c;
		if(!l && !r && !c) break; // 종료 조건 0 0 0
		char board[l][r][c];
		int dist[l][r][c]; memset(dist,-1,sizeof(dist)); // 이동거리 배열 -1로 초기화
		queue<tuple<int,int,int>> q;
		for(int i=0;i<l;i++)
			for(int j=0;j<r;j++)
				for(int k=0;k<c;k++)
				{
					cin >> board[i][j][k];
					if(board[i][j][k] == 'S')
					{
						dist[i][j][k] = 0; // 시작지점 체크
						q.push({i,j,k});
					}
				}
		int escape = 0; // 탈출 플래그
		while(!q.empty() && !escape)
		{
			cur = q.front();
			q.pop();
			for(int dir=0;dir<6;dir++) // 3차원이어서 배열을 참조할때 각 인덱스를 올바른 값으로 넣어주어야한다.
			{						   // 상당히 헷갈리므로 주의하자!
				nx = get<1>(cur) + dx[dir];
				ny = get<2>(cur) + dy[dir];
				nz = get<0>(cur) + dz[dir];
				if(nx<0 || ny<0 || nz<0 || nx>=r || ny>=c || nz>=l) continue;
				if(board[nz][nx][ny]=='#' || dist[nz][nx][ny]!= -1) continue;
				dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
				if(board[nz][nx][ny]=='E') // 탈출구를 발견하면
				{
					cout << "Escaped in "<<dist[nz][nx][ny] << " minute(s).\n";
					escape = 1;
					break;
				}
				q.push({nz,nx,ny});
			}
		}
		if(!escape) cout << "Trapped!\n"; // 탈출을 못했다면
	}
}