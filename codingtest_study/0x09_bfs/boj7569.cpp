/* 토마토 */
/* 14:06 ~ 15:15 */
#include <iostream>
#include <queue>
#include <tuple>//튜플 오류나면 gcc -std=c++11 로 컴파일
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,m,h,ans = 0;
	int dx[6] = {-1,0,1,0,0,0}, dy[6] = {0,1,0,-1,0,0}, dz[6] = {0,0,0,0,1,-1};//3차원 방향
	queue<tuple<int,int,int> > q;//pair와 비슷한 클래스이다. 갯수의 차이. pair => 2, tuple => 3
	cin >> m >> n >> h;
	int board[h][n][m];
	for(int i=0;i<h;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<m;k++)
			{
				cin >> board[i][j][k];
				if(board[i][j][k] == 1) q.push(make_tuple(i,j,k));//1일때 큐에 넣어줌
			}
	while(q.size())
	{
		tuple<int,int,int> t = q.front();
		q.pop();
		for(int dir=0;dir<6;dir++)
		{
			int nx = get<1>(t) + dx[dir];//3차원이여서 방향 설정할때 착각하기쉬우니 주의할것
			int ny = get<2>(t) + dy[dir];
			int nz = get<0>(t) + dz[dir];
			if(nx<0 || ny<0 || nz<0 || nx>=n || ny>=m ||nz>=h) continue;
			if(board[nz][nx][ny]!=0) continue;
			q.push(make_tuple(nz,nx,ny));
			board[nz][nx][ny] = board[get<0>(t)][get<1>(t)][get<2>(t)] + 1;//익는 최소시간을 구해야하기때문에 이전값에서 +1 해준다.
		}
	}
	for(int i=0;i<h;i++)
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				if(!board[i][j][k])//board에 0이 남아있다면 다익은것이 아니기 때문에
				{
					cout << "-1\n";
					exit(0);
				}
				ans = max(ans,board[i][j][k]);
			}
		}
	cout << ans-1 << "\n";
}